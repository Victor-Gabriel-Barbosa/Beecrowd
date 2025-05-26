#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, R;
    cin >> N >> R;
    
    vector<int> temp(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> temp[i];
    }
    
    // Criar lista de adjacências
    vector<vector<pair<int, int>>> adj(N + 1);
    for (int i = 0; i < R; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        adj[x].push_back({y, d});
        adj[y].push_back({x, d});
    }
    
    int Q;
    cin >> Q;
    
    while (Q--) {
        int A, B, K, T;
        cin >> A >> B >> K >> T;
        
        // Criar lista de planetas ordenados por temperatura
        vector<pair<int, int>> planets; // {temperatura, planeta}
        for (int i = 1; i <= N; i++) {
            planets.push_back({temp[i], i});
        }
        
        // Ordenar por temperatura
        sort(planets.begin(), planets.end());
        
        // Determinar planetas válidos
        set<int> valid_planets;
        
        if (T == 0) { // K menores temperaturas
            for (int i = 0; i < K; i++) {
                valid_planets.insert(planets[i].second);
            }
        } else { // K maiores temperaturas
            for (int i = N - K; i < N; i++) {
                valid_planets.insert(planets[i].second);
            }
        }
        
        // Adicionar origem e destino (sempre válidos)
        valid_planets.insert(A);
        valid_planets.insert(B);
        
        // Dijkstra apenas com planetas válidos
        vector<int> dist(N + 1, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        dist[A] = 0;
        pq.push({0, A});
        
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if (d > dist[u]) continue;
            
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                
                // Verificar se o planeta de destino é válido
                // Se for A ou B, sempre é válido
                // Se não, precisa estar na lista de planetas válidos
                if (v != A && v != B && valid_planets.find(v) == valid_planets.end()) {
                    continue;
                }
                
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        if (dist[B] == INF) {
            cout << -1 << "\n";
        } else {
            cout << dist[B] << "\n";
        }
    }
    
    return 0;
}