#include <iostream>
using namespace std;
int main() {
	int x; 
	while (cin>>x) {
		if (x & 1) {
			cout<<x<<" is odd.\n";
		} else cout<<x<<" is even.\n";
	}
	return 0;
}

