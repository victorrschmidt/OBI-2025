// Subtarefa 4
// Visto que todas as conexões são rodovias, para cada componente
// conexo do grafo, precisamos verificar quantas arestas extras
// cada um tem, e somar tudo. Se conseguirmos tirar todas as arestas
// extras, cada componente conexo será uma árvore, e o sistema será
// simples.

// Sendo assim, precisamos verificar o número de arestas extras E,
// e verificar se E <= K. Se sim, a resposta é 'S'.
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int MAXN = 100010;

vector<vector<pair<int, int>>> adj(MAXN);
vector<bool> visitado(MAXN);
vector<int> vertices;
int extra = 0;

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
    extra += soma / 2 - vertices.size() + 1;
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

    if (extra <= k) {
        cout << "S\n";
    }
    else {
        cout << "N\n";
    }

    return 0;
}