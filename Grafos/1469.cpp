#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, I;

  while (cin >> N >> M >> I) {
    vector<int> idade(N + 1);
    vector<vector<int>> gerencia(N + 1); // gerencia[i] = lista de quem i gerencia
    vector<vector<int>> gerenciado_por(N + 1); // gerenciado_por[i] = lista de quem gerencia i

    // Lê as idades
    for (int i = 1; i <= N; i++) cin >> idade[i];

    // Lê as relações de gerência
    for (int i = 0; i < M; i++) {
      int x, y;
      cin >> x >> y;
      gerencia[x].push_back(y);
      gerenciado_por[y].push_back(x);
    }

    // Processa as instruções
    for (int i = 0; i < I; i++) {
      char operacao;
      cin >> operacao;

      if (operacao == 'T') {
        int A, B;
        cin >> A >> B;

        // Troca as posições de A e B na hierarquia
        // Primeiro, salva as relações atuais
        vector<int> A_gerencia = gerencia[A];
        vector<int> A_gerenciado_por = gerenciado_por[A];
        vector<int> B_gerencia = gerencia[B];
        vector<int> B_gerenciado_por = gerenciado_por[B];

        // Remove A e B de todas as listas
        for (int pessoa : A_gerencia) {
          gerenciado_por[pessoa].erase(
              find(gerenciado_por[pessoa].begin(), gerenciado_por[pessoa].end(), A));
        }
        for (int pessoa : A_gerenciado_por) {
          gerencia[pessoa].erase(
              find(gerencia[pessoa].begin(), gerencia[pessoa].end(), A));
        }
        for (int pessoa : B_gerencia) {
          gerenciado_por[pessoa].erase(
              find(gerenciado_por[pessoa].begin(), gerenciado_por[pessoa].end(), B));
        }
        for (int pessoa : B_gerenciado_por) {
          gerencia[pessoa].erase(
              find(gerencia[pessoa].begin(), gerencia[pessoa].end(), B));
        }

        // Limpa as listas de A e B
        gerencia[A].clear();
        gerenciado_por[A].clear();
        gerencia[B].clear();
        gerenciado_por[B].clear();

        // Reconecta com as posições trocadas
        for (int pessoa : B_gerencia) {
          gerencia[A].push_back(pessoa);
          gerenciado_por[pessoa].push_back(A);
        }
        for (int pessoa : B_gerenciado_por) {
          gerenciado_por[A].push_back(pessoa);
          gerencia[pessoa].push_back(A);
        }
        for (int pessoa : A_gerencia) {
          gerencia[B].push_back(pessoa);
          gerenciado_por[pessoa].push_back(B);
        }
        for (int pessoa : A_gerenciado_por) {
          gerenciado_por[B].push_back(pessoa);
          gerencia[pessoa].push_back(B);
        }

      } else { // operacao == 'P'
        int E;
        cin >> E;

        // Encontra o gerente mais jovem usando DFS
        vector<bool> visitado(N + 1, false);
        vector<int> pilha;
        int idade_mais_jovem = INT_MAX;

        // Adiciona todos os gerentes diretos na pilha
        for (int gerente : gerenciado_por[E]) pilha.push_back(gerente);

        // DFS para encontrar todos os gerentes (diretos e indiretos)
        while (!pilha.empty()) {
          int atual = pilha.back();
          pilha.pop_back();

          if (visitado[atual]) continue;
          visitado[atual] = true;

          idade_mais_jovem = min(idade_mais_jovem, idade[atual]);

          // Adiciona os gerentes do gerente atual
          for (int gerente : gerenciado_por[atual]) if (!visitado[gerente]) pilha.push_back(gerente);
        }

        if (idade_mais_jovem == INT_MAX) cout << "*" << endl;
        else cout << idade_mais_jovem << endl;
      }
    }
  }

  return 0;
}