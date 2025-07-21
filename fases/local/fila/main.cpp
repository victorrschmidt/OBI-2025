#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int maior_altura = a[n - 1];
    int contador = 0;

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] <= maior_altura) {
            contador++;
        }
        else {
            maior_altura = a[i];
        }
    }

    cout << contador << '\n';

    return 0;
}