# Gráfico de Barras

- A solução resolve todas as subtarefas.
- Complexidade de tempo: **$O(n \cdot x)$**.

O problema consiste em construir uma matriz binária que representa um gráfico. Considerando $a$ a lista de quantas pessoas preferem cada um dos $n$ brinquedos, a matriz $m$ terá $max(a) = h$ linhas e $n$ colunas.

A partir da primeira coluna até a última, iremos preencher o valor das linhas na coluna $i$, de baixo para cima, conforme a quantidade de pessoas que preferem o brinquedo $i$.

Formalmente, iremos preencher com $1$ $m_{h - j - 1 \ i}$ enquanto $j < a_{i}$, para cada umas das $n$ colunas.

## Solução

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int h = -1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        h = max(h, a[i]);
    }

    vector<vector<int>> matriz(h, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i]; j++) {
            matriz[h - j - 1][i] = 1;
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << " \n"[j == n - 1];
        }
    }

	return 0;
}
```