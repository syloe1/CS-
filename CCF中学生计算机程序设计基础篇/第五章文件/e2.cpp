/*
�ļ���������֪�ļ����в�����1000�����������������
���ǵĺͣ���֤����10000���ڣ���
�����ʽ���ļ�sum.in���� 1�У������������Χ�� [1��1000]��
�����ʽ���ļ�sum.out�������һ��������
����������
10 5 6 9
���������
  30
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("sum.in");
ofstream fout("sum.out");
int x, sum;
int main() {
	sum = 0;
	//while (!fin.eof()) û���ļ�������ѭ�� 
	while (fin>>x) {
		sum += x;
	}
	fout<<sum<<endl;
	return 0;
}
