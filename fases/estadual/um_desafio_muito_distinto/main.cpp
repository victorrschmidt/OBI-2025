#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int p;
    cin >> p;

    while (p--) {
        ll l, a, b;
        cin >> l >> a >> b;

        ll esquerda = 0;
        ll direita = b - a + 1;
        ll melhor = b - a + 1;

        while (esquerda <= direita) {
            ll meio = (esquerda + direita) / 2;
            ll soma = (a + a + meio - 1) * meio / 2;

            if (soma >= l) {
                direita = meio - 1;
                melhor = meio;
            }
            else {
                esquerda = meio + 1;
            }
        }

        cout << melhor << '\n';
    }

    return 0;
}
