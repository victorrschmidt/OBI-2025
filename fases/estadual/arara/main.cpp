#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (m >= n + (n - 1) * 4) {
        cout << "S\n";
    }
    else {
        cout << "N\n";
    }

    return 0;
}