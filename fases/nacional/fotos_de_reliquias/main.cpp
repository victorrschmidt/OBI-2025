#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int tamanho(pair<int, int>& intervalo) {
    return intervalo.second - intervalo.first + 1;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<pair<int, int>> intervalos;
    long long resposta = 0;

    for (auto& i : a) {
        cin >> i;
        resposta += i;
    }

    // Se não existe nenhum '1' no array, não é possível formar um intervalo válido
    if (resposta == 0) {
        cout << "0\n";
        return 0;
    }

    int inicio = -1;

    // Salvar as sequências de '0'
    for (int i = 0; i < n; i++) {
        if (a[i] == 0 && inicio == -1) {
            inicio = i;
        }
        else if (a[i] == 1 && inicio != -1) {
            intervalos.push_back({inicio, i - 1});
            inicio = -1;
        }
    }

    if (inicio != -1) {
        intervalos.push_back({inicio, n - 1});
    }

    // Verificar a resposta
    for (int i = 0; i < intervalos.size(); i++) {
        // Somar o número de zeros com o '1' adjacente
        resposta += tamanho(intervalos[i]);

        // Se a sequência não está em uma das pontas i.e.
        // não contém o primeiro nem o último elemento do array
        if ((i != 0 || intervalos[i].first != 0) && (i != intervalos.size() - 1 || intervalos[i].second != n - 1)) {
            // É possível somá-la com o outro '1' adjacente
            resposta += tamanho(intervalos[i]);
        }

        // Se a sequência está divida por um '1' com uma sequência
        // à direita, é possível multiplicar seus tamanhos e somar à resposta
        if (i < intervalos.size() - 1 && intervalos[i].second == intervalos[i + 1].first - 2) {
            resposta += tamanho(intervalos[i]) * tamanho(intervalos[i + 1]);
        }
    }

    cout << resposta << '\n';

    return 0;
}