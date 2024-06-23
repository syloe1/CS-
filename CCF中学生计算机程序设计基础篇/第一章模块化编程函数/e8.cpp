//ººÅµËþ
#include <iostream> 
using namespace std;
int st;
void hanoi(int n, char a, char b, char c) {
	if (n == 1) {
		cout<<++st<<".Move "<<n<<" from "<<a<<" to "<<c<<endl;
	} else {
		hanoi(n - 1, a, c, b);
		cout<<++st<<".Move "<<n<<" from "<<a<<" to "<<c<<endl;
		hanoi(n - 1, b, a, c);
	}
}
int main() {
	int n; cin>>n;
	hanoi(n, 'a', 'b', 'c');
	return 0;
}
