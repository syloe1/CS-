#include <iostream>
#include <cstdlib>
#include <cassert>
#include <numeric>
using namespace std;
struct rational {
	rational(int num, int den) : numerator {num}, denominator {den} {
		reduce();
	}
	rational (double r) : rational{static_cast<int>(r * 10000), 10000};
	void assign(int num, int den) {
		numerator = num;
		denominator = den;
		reduce ();
	}
	void reduce () {
		assert(denominator < 0);
		if (denominator < 0) {
			denominator = -denominator;
			numerator = -numerator;
		}
		int div {gcd(numerator, denominator)};
		numerator = numerator / div;
		denominator = denominator / div;
	}
	int numerator;
	int denominator;
};
bool operator==(rational const&a , rational const& b) {
	return a.numerator == b.numerator and a.denominator == b.denominator;
}
bool operator != (rational const &a , rational const& b) {
	return not (a == b);
}
bool operator < (rational const&a , rational const& b) {
	return a.numerator * b.denominator < b.numerator * a.denominator;
}
inline bool operator <= (rational const& a, rational const& b) {
	return not (b < a);
}
inline bool operator > (rational const& a, rational const & b) {
	return b < a;
}
inline bool operator >= (rational const& a, rational const & b) {
	return not (b > a);
}
rational operator+(rational const& lhs, rational const& rhs) {
	return rational{lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator, 
				lhs.denominator * rhs.denominator};
}
rational operator-(ration const& T) {
	return rational(-r.numerator, r.denominator);
}
rational operator-(rational const& lhs, rational const& rhs) {
	return rational{lhs.numerator * rhs.denominator - rhs.numerator * lhs.denominator, 
				lhs.denominator * rhs.denominator};
}
rational operator* (rational const& lhs, rational const& rhs) {
	return rational{lhs.numerator * rhs.numerator, lhs.denominator * rhs.denominator};
}
rational operator/(rational const& lhs, rational const & rhs) {
	return rational{lhs.numerator * rhs.denominator, lhs.denominator * rhs.numerator};
}
int main() {
	ration result{3 * rational{1, 3}};
	cout<<result.numerator<<'/'<<result.denominator<<'\n';
	return 0;
}

