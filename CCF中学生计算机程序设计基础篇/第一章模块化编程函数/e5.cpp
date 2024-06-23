//µİ¹éÇó½×³Ë
#include <iostream> 
using namespace std;
int f(int n) {
	if (n == 1) return 1;
	else return n * f(n - 1);
}
int main() {
	int n;
	cin>>n; cout<<f(n)<<endl;
	return 0;
}
