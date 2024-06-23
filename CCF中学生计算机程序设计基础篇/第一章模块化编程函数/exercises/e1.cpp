//数根可以通过把一个数的各个位上的数字加起来得到。
//如果得到的是一位数， 那么这个数就是数根 
#include <iostream>
using namespace std;

int gg(int x) {
	while (x > 9) {
		int a = 0;
		while (x) {
			a += x % 10;
			x /= 10;
		}
		x = a;
	}
	return x;
}
int main() {
	int n; cin>>n;
	cout<<gg(n)<<endl;
	return 0;
}
