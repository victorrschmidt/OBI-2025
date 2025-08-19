#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 110;

int n, m;
int matriz[MAXN][MAXN];

int custo_de_troca(int paridade_inicial) {
    int custo = 0;
    int paridade_atual = paridade_inicial;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((matriz[i][j] & 1) != paridade_atual) {
                custo++;
            }
            paridade_atual ^= 1;
        }
    }

    return custo;
}

void ajustar_paridade(int paridade_inicial){
    int paridade_atual = paridade_inicial;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((matriz[i][j] & 1) != paridade_atual) {
                matriz[i][j]++;
            }
            paridade_atual ^= 1;
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matriz[i][j];
        }
    }

    int custo_impar = custo_de_troca(1);
    int custo_par = custo_de_troca(0);

    if (custo_impar < custo_par) {
        cout << custo_impar << '\n';
        ajustar_paridade(1);
    }
    else {
        cout << custo_par << '\n';
        ajustar_paridade(0);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matriz[i][j] << " \n"[j == m - 1];
        }
    }

    return 0;
}
