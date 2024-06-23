//ÅÀÂ¥Ìİ
#include <iostream> 
using namespace std;
int gg(int n) {
	if (n <= 2) {
		return n;
	}
	int a = 1, b = 2, c ;
	for (int i = 3; i <= n; i++) {
		c = a + b;
		a = b; b = c;
	}
	return c;
}
int main() {
	int n; cin>>n;
	cout<<gg(n)<<endl;
	return 0;
}
