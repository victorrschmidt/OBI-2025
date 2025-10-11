// Subtarefa 3
// Visto que todas as conexões são rodovias e que o grafo
// é inteiramente conexo, precisamos verificar se tirando
// até K arestas do grafo, ele passará a ser uma árvore
// (ter V vértices e V-1 arestas).

#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    if (n > m - k) {
        cout << "S\n";
    }
    else {
        cout << "N\n";
    }

    return 0;
}