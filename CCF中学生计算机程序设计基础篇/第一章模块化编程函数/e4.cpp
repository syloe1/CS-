//计算最小公倍数
#include <iostream> 
using namespace std;

long long x, y;

long long gcd(long long x, long long y) {
    while (y != 0) {
        long long r = x % y;
        x = y;
        y = r;
    }
    return x;
}

long long lcm() {
    return x * y / gcd(x, y);
}

int main() {
    cin >> x >> y;
    cout << lcm() << endl;
    return 0;
}

