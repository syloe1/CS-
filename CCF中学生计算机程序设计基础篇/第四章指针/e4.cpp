#include <iostream>
using namespace std;
int a[] = {10,11,12,13,14,15};
int *p = a + 4;
int main() {
	cout<<*a<<endl;
	cout<<*(a+3)<<endl;
	cout<<(*++p)<<endl;
	return 0;
}
