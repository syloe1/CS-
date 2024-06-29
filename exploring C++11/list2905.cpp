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
		reduce(); //这个构造函数是 rational 结构的另一个重载版本，它接受一个整数参数 num 并使用初始化列表来初始化成员变量 numerator 和 denominator。这里，numerator 被初始化为传入的参数 num，而 denominator 被初始化为 1，这意味着这个构造函数创建的有理数实际上是一个整数（或整比数）。
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
