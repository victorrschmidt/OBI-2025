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

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        resposta += a[i];
    }

    int inicio = -1;

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

    for (int i = 0; i < intervalos.size(); i++) {
        resposta += tamanho(intervalos[i]);

        if ((i != 0 || intervalos[i].first != 0) && (i != intervalos.size() - 1 || intervalos[i].second != n - 1)) {
            resposta += tamanho(intervalos[i]);
        }
        if (i < intervalos.size() - 1 && intervalos[i].second == intervalos[i + 1].first - 2) {
            resposta += tamanho(intervalos[i]) * tamanho(intervalos[i + 1]);
        }
    }

    cout << resposta << '\n';

    return 0;
}