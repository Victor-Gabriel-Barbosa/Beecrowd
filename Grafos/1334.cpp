#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <tuple> // Required for std::tuple

// DSU data structures
std::vector<int> parent;
std::vector<long long> sign; 
std::vector<long long> offset;
std::vector<bool> is_root_val_known;
std::vector<long long> root_val;

// find_set also performs path compression and updates sign/offset
int find_set(int i) {
    if (parent[i] == i) {
        return i;
    }
    int original_parent_node = parent[i];
    parent[i] = find_set(original_parent_node); // parent[i] is now the true root.
                                                // find_set(original_parent_node) has updated 
                                                // sign[original_parent_node] and offset[original_parent_node]
                                                // to be relative to this true root.

    long long sign_i_to_original_parent = sign[i];
    long long offset_i_to_original_parent = offset[i];

    // Update sign[i] and offset[i] to be relative to the true root (parent[i])
    // g_i = sign_i_to_original_parent * g_{original_parent_node} + offset_i_to_original_parent
    // g_{original_parent_node} = sign[original_parent_node] * g_{true_root} + offset[original_parent_node]
    sign[i] = sign_i_to_original_parent * sign[original_parent_node];
    offset[i] = sign_i_to_original_parent * offset[original_parent_node] + offset_i_to_original_parent;
    
    return parent[i];
}

void solve_test_case() {
    int M, Q;
    std::cin >> M >> Q;
    if (M == 0 && Q == 0) {
        exit(0); 
    }

    std::vector<std::tuple<int, int, int>> measurements(M);
    std::vector<std::pair<int, int>> queries(Q);
    std::set<int> all_coords_set;

    for (int i = 0; i < M; ++i) {
        std::cin >> std::get<0>(measurements[i]) >> std::get<1>(measurements[i]) >> std::get<2>(measurements[i]);
        all_coords_set.insert(std::get<0>(measurements[i]));
        all_coords_set.insert(std::get<1>(measurements[i]));
    }
    for (int i = 0; i < Q; ++i) {
        std::cin >> queries[i].first >> queries[i].second;
        all_coords_set.insert(queries[i].first);
        all_coords_set.insert(queries[i].second);
    }

    std::map<int, int> coord_to_id;
    int next_id = 0;
    for (int coord : all_coords_set) {
        coord_to_id[coord] = next_id++;
    }

    int num_distinct_coords = next_id;

    if (num_distinct_coords == 0) { // Handles M=0 and Q=0 if queries also involved no coords
        for (int i = 0; i < Q; ++i) { // If Q > 0 but no coords, this loop won't run if num_distinct_coords is 0
             std::cout << "*" << std::endl; // This case should ideally not happen if Q > 0
        }
    } else {
        parent.assign(num_distinct_coords, 0);
        sign.assign(num_distinct_coords, 1);
        offset.assign(num_distinct_coords, 0);
        is_root_val_known.assign(num_distinct_coords, false);
        root_val.assign(num_distinct_coords, 0);

        for (int i = 0; i < num_distinct_coords; ++i) {
            parent[i] = i;
        }
    }
    
    for (const auto& meas : measurements) {
        int X_coord = std::get<0>(meas);
        int Y_coord = std::get<1>(meas);
        long long A_val = std::get<2>(meas);

        int idX = coord_to_id[X_coord];
        int idY = coord_to_id[Y_coord];

        if (X_coord == Y_coord) { 
            int rootX = find_set(idX);
            if (is_root_val_known[rootX]) {
                // Consistency check
            } else {
                is_root_val_known[rootX] = true;
                root_val[rootX] = sign[idX] * (A_val - offset[idX]);
            }
        } else { 
            int rootX = find_set(idX);
            int rootY = find_set(idY);

            if (rootX == rootY) {
                if (!is_root_val_known[rootX]) {
                    long long sum_of_signs = sign[idX] + sign[idY];
                    if (sum_of_signs != 0) { 
                        is_root_val_known[rootX] = true;
                        root_val[rootX] = (A_val - (offset[idX] + offset[idY])) / sum_of_signs;
                    }
                }
            } else { 
                bool knownX = is_root_val_known[rootX];
                bool knownY = is_root_val_known[rootY];
                
                // Standard union: make root with known value the parent, or rootX parent of rootY by default.
                // idX and idY's sign/offset are already relative to rootX and rootY respectively.
                if (knownY && !knownX) { // Make rootY parent of rootX
                    parent[rootX] = rootY;
                    // g_rootX = new_sign * g_rootY + new_offset
                    // from (sign[idX]*g_rootX + off[idX]) + (sign[idY]*g_rootY + off[idY]) = A_val
                    // sign[idX]*g_rootX = A_val - off[idX] - off[idY] - sign[idY]*g_rootY
                    // g_rootX = sign[idX]*(A_val - off[idX] - off[idY]) - sign[idX]*sign[idY]*g_rootY
                    sign[rootX] = -sign[idX] * sign[idY];
                    offset[rootX] = sign[idX] * (A_val - offset[idX] - offset[idY]);
                } else { // Make rootX parent of rootY (either rootX known, or both unknown, or both known)
                    parent[rootY] = rootX;
                    // g_rootY = new_sign * g_rootX + new_offset
                    // from (sign[idX]*g_rootX + off[idX]) + (sign[idY]*g_rootY + off[idY]) = A_val
                    // sign[idY]*g_rootY = A_val - off[idX] - off[idY] - sign[idX]*g_rootX
                    // g_rootY = sign[idY]*(A_val - off[idX] - off[idY]) - sign[idY]*sign[idX]*g_rootX
                    sign[rootY] = -sign[idY] * sign[idX];
                    offset[rootY] = sign[idY] * (A_val - offset[idX] - offset[idY]);
                }
            }
        }
    }

    for (const auto& q_pair : queries) {
        int X_prime_coord = q_pair.first;
        int Y_prime_coord = q_pair.second;

        int idX_p = coord_to_id[X_prime_coord];
        int idY_p = coord_to_id[Y_prime_coord];
        
        if (X_prime_coord == Y_prime_coord) { 
            int rootX_p = find_set(idX_p);
            if (is_root_val_known[rootX_p]) {
                long long val_gX_p = sign[idX_p] * root_val[rootX_p] + offset[idX_p];
                std::cout << val_gX_p << std::endl;
            } else {
                std::cout << "*" << std::endl;
            }
        } else { 
            int rootX_p = find_set(idX_p);
            int rootY_p = find_set(idY_p);

            bool known_val_at_rootX = is_root_val_known[rootX_p];
            bool known_val_at_rootY = is_root_val_known[rootY_p];

            if (known_val_at_rootX && known_val_at_rootY) {
                long long val_gX_p = sign[idX_p] * root_val[rootX_p] + offset[idX_p];
                long long val_gY_p = sign[idY_p] * root_val[rootY_p] + offset[idY_p];
                std::cout << (val_gX_p + val_gY_p) << std::endl;
            } else if (rootX_p == rootY_p) { 
                long long sum_of_signs_for_g_root = sign[idX_p] + sign[idY_p];
                if (sum_of_signs_for_g_root == 0) {
                    long long sum_val = offset[idX_p] + offset[idY_p];
                    std::cout << sum_val << std::endl;
                } else {
                    std::cout << "*" << std::endl; 
                }
            } else { 
                std::cout << "*" << std::endl;
            }
        }
    }
    std::cout << "-" << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (true) {
        solve_test_case(); 
    }
    return 0;
}