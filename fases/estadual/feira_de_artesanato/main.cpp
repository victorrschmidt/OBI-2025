#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<pair<int, int>> objetos(n);  // {tipo, preco}
    vector<priority_queue<pair<int, int>>> lista_tipo(t + 1);  // {preco, id}
    priority_queue<vector<int>> lista_preco;  // {preco, tipo, id}
    vector<bool> podecomprar(n, true);

    for (int i = 0; i < n; i++) {
        cin >> objetos[i].second;
    }

    for (int i = 0; i < n; i++) {
        cin >> objetos[i].first;
    }

    for (int i = 0; i < n; i++) {
        int preco = objetos[i].first;
        int tipo = objetos[i].second;
        lista_preco.push({-preco, -tipo, i});
        lista_tipo[tipo].push({-preco, i});
    }

    long long total = 0;
    int c;
    cin >> c;

    while (c--) {
        int preco, tipo, id;
        cin >> tipo;

        if (tipo == 0) {
            while (!lista_preco.empty()) {
                preco = -lista_preco.top()[0];
                tipo = -lista_preco.top()[1];
                id = lista_preco.top()[2];
                lista_preco.pop();

                if (podecomprar[id]) {
                    total += preco;
                    podecomprar[id] = 0;
                    break;
                }
            }
        }
        else {
            while (!lista_tipo[tipo].empty()) {
                preco = -lista_tipo[tipo].top().first;
                id = lista_tipo[tipo].top().second;
                lista_tipo[tipo].pop();

                if (podecomprar[id]) {
                    total += preco;
                    podecomprar[id] = 0;
                    break;
                }
            }
        }
    }

    cout << total << '\n';

    return 0;
}
