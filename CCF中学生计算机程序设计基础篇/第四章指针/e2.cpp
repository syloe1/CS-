//输入N个整数， 使用指针变量访问输出
#include <iostream> 
using namespace std;
int a[100], N;
int main() {
	cin>>N;
	for (int i = 0; i < N; i++) {
		cin>>a[i];
	}
	int *p = &a[0];
	for (int i = 0; i < N; i++) {
		cout<<*p<<endl;
		p++;
	}
	return 0;
}
/*
*p = a[0], P++ 向后跳过一个整数空间， 达到后一个整数
(p+3)是指向后面第三个整数的地址 
*/
