//ʹ��typedef���庯��ָ�롣 
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
