//输入两个不同的浮点数， 通过指针把最大值+10； 
#include <iostream> 
using namespace std;
int a, b;
int *p;
int main() {
	cin>>a>>b;
	if (a > b) p = &a;
	else p = &b;
	*p += 10;
	cout<<*p<<endl;
	return 0;
}
/*
p --------------- &a
*p --------------- a
*p = 3 ------  a = 3 
*/
