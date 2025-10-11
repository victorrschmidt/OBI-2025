// Subtarefa 2
// Visto que todas as conexões são hidrovias, o sistema não mudou
// ao longo dos K anos. Ou seja, apenas precisamos verificar se
// o sistema é simples.

// Para verificar se o sistema é simples, precisamos verificar
// se todos os componentes conexos são árvores. Isto é, possuem V
// vértices e V-1 arestas.
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
const int MAXN = 100010;

vector<vector<pair<int, int>>> adj(MAXN);
vector<bool> visitado(MAXN);
vector<int> vertices;
char resposta = 'S';

void dfs(int u) {
    visitado[u] = true;
    vertices.push_back(u);
    for (auto [v, t] : adj[u]) {
        if (!visitado[v]) {
            dfs(v);
        }
    }
}

void check(int u) {
    if (visitado[u]) return;
    vertices.clear();
    dfs(u);
    int soma = 0;
    for (auto v : vertices) {
        soma += adj[v].size();
    }
    if (soma / 2 != vertices.size() - 1) {
        resposta = 'N';
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }

    for (int i = 1; i <= n; i++) {
        check(i);
    }

    cout << resposta << '\n';

    return 0;
}