#include <iostream>
using namespace std;
int main() {
	int sum{0};
	int count{};
	int x;
	while (cin>>x) {
		sum = sum + x;
		count = count + 1;
	}
	if (count != 0) cout<<"average = "<<sum / count<<'\n';
	return 0;
}

