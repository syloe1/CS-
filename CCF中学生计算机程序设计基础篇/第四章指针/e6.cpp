//使用typedef定义函数指针。 
#include<iostream>
using namespace std;
int add(int,int);
typedef  int(*addP)(int,int);
int main() {
	addP fp=add;
	cout<<fp(2,5)<<endl;
}

int add(int a,int b) {
	return a + b;
}
