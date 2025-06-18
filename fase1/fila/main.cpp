#include <iostream>
#include <vector>
using namespace std;

// 1 3 5 2

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int maior_altura = 0;
    int contador = 0;

    for (int i = n - 2; i >= 0; i--) {
        if (maior_altura <= a[i]) {
            maior_altura = a[i];
        }
        else {
            contador++;
        }
    }

    cout << contador << '\n';

    return 0;
}