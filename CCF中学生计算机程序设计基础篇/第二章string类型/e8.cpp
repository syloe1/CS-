//��N���˵�������������ǰ��������ֵ������������
//�����ʽ����1�У���һ������N��N�ķ�Χ��[1��10000]�������
//2 �е���N+1�У�ÿ����1�������������ɲ�����50��Сд��ĸ��ɡ�
//�����ʽ��N�У�ÿ��һ��������
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n;
string a[100000];
int main() {
	cin>>n;
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		cout<<a[i]<<endl;
	}
	return 0;
}
