//a1  = 1, a2 = 2, an = 2*an-1 + an-2
#include <iostream>
using namespace std;

const int mod = 32767;

int pell(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    int a = 1, b = 2, c;
    for (int i = 3; i <= n; i++) {
        c = (2 * b + a) % mod;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    cin >> n;
    cout << pell(n) << endl;
    return 0;
}

