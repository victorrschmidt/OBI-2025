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