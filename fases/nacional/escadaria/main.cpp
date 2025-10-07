#include <iostream>
#include <vector>
using namespace std;

typedef struct {
    int indice, altura;
} Degrau;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<Degrau> degraus;

    for (auto& i : a) {
        cin >> i;
    }

    // Salvar a lista de degraus de pé
    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            degraus.push_back({i, a[i]});
        }
    }

    // Se existem degraus caídos à esquerda do primeiro degrau,
    // preenchemos de forma crescente da direita para a esquerda
    if (degraus.front().indice != 0) {
        int altura = degraus.front().altura + 1;
        for (int i = degraus.front().indice - 1; i >= 0; i--) {
            a[i] = altura;
            altura++;
        }
    }

    // Se existem degraus caídos à direita do último degrau,
    // preenchemos de forma crescente da esquerda para a direita
    if (degraus.back().indice != n - 1) {
        int altura = degraus.back().altura + 1;
        for (int i = degraus.back().indice + 1; i < n; i++) {
            a[i] = altura;
            altura++;
        }
    }

    // Igualar o tamanho dos degraus adjacentes. O tamanho do maior será
    // o escolhido, pois sempre existirá uma solução possível.
    for (int i = 0; i < degraus.size() - 1; i++) {
        auto esq = degraus[i];
        auto dir = degraus[i + 1];

        if (esq.altura > dir.altura) {
            int altura = dir.altura + 1;
            for (int j = dir.indice - 1; altura != esq.altura + 1; j--) {
                a[j] = altura;
                altura++;
            }
        }
        else if (esq.altura < dir.altura) {
            int altura = esq.altura + 1;
            for (int j = esq.indice + 1; altura != dir.altura + 1; j++) {
                a[j] = altura;
                altura++;
            }
        }
    }

    int esq = -1;

    // Preencher os espaços vazios entre os degraus adjacentes
    for (int i = 0; i < n; i++) {
        if (a[i] == -1 && esq == -1) {
            esq = i;
        }
        else if (a[i] != -1 && esq != -1) {
            int dir = i - 1;
            int altura = a[esq - 1] + 1;
            while (esq <= dir) {
                a[esq] = altura;
                a[dir] = altura;
                esq++;
                dir--;
                altura++;
            }
            esq = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }

    return 0;
}