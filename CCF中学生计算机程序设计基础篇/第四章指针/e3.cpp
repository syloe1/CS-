//∂‡÷ÿ÷∏’Î
#include <iostream> 
using namespace std;
int a = 10;
int *p;
int **pp;
int main() {
	p = &a;
	pp = &p;
	cout<<a<<"="<<*p<<"="<<**pp<<endl;
	return 0;
}
