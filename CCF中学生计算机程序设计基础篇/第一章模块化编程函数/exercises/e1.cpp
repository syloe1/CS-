//��������ͨ����һ�����ĸ���λ�ϵ����ּ������õ���
//����õ�����һλ���� ��ô������������� 
#include <iostream>
using namespace std;

int gg(int x) {
	while (x > 9) {
		int a = 0;
		while (x) {
			a += x % 10;
			x /= 10;
		}
		x = a;
	}
	return x;
}
int main() {
	int n; cin>>n;
	cout<<gg(n)<<endl;
	return 0;
}
