//����N�������� ʹ��ָ������������
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
*p = a[0], P++ �������һ�������ռ䣬 �ﵽ��һ������
(p+3)��ָ���������������ĵ�ַ 
*/
