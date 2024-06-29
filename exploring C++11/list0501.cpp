#include <iostream>
using namespace std;
int main() {
	cout<<"Enter a number: ";
	int x; cin>>x;
	cout<<"Enter another number: ";
	int y; cin>>y;
	int z{x + y};
//int z (x + y);
	cout<<"The sum of "<<x<<" and "<<y<<" is "z<<"\n";
	return 0;
}

