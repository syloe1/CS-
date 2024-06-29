#include <cassert>
#include <cstdlib>
#include <iostream>
using namespace std;
int gcd(int n, int m) {
	n = abs(n);
	while (m != 0) {
		int t(n %  m)	;
		n = m;
		m = t;
	} 	return n;
}
struct rational {
	rational(int num, int den)  : numerator{num}, denominator{den} {
		reduce(); //������캯���� rational �ṹ����һ�����ذ汾��������һ���������� num ��ʹ�ó�ʼ���б�����ʼ����Ա���� numerator �� denominator�����numerator ����ʼ��Ϊ����Ĳ��� num���� denominator ����ʼ��Ϊ 1������ζ��������캯��������������ʵ������һ��������������������
	}
	void assign(int num, int den) {
		numerator = num;
		denominator = den;
		reduce();
	}
	void reduce() {
		assert(denominator != 0);
		int div{gcd(numerator, denominator)};
		numerator = numerator / div;
		denominator = denominator / div;
	}
	int numerator;
	int denominator;
};
int main() {
	rational pi{1420, 452};
	cout<<"pi is about "<<pi.numerator<<"/"<<pi.denominator<<'\n';
	
	return 0;
}
