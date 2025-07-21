#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if ((c - b + d - 1) / d <= (c - a) / d) {
        cout << "S\n";
    }
    else {
        cout << "N\n";
    }

    return 0;
}