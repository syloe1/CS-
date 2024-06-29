#include <cassert>
#include <cstdlib>
#include <istream>
#include <ostream>
#include <sstream>
using namespace std;
int gcd(int n, int m) {
	n = abs(n);
	while (m != 0) {
		int t(n % m);
		n = m;
		m = t;
	}
	return n;
}
struct rational {
	rational() : numerator {0}, denominator {1} {
		//empty
	}
	rational(int num) : numerator {num}, denominator {1} {
		//empty
	}
	rational(int num, int den) : numerator {num}, denominator {den} {
		reduce();
	}
	ration(double r) : rational(static_cast<int>(r * 10000), 10000) {
		//empty
	}
	rational& operator=(ration const & that) {
		this->numerator = that.numerator;
		this->denominator = that.denominator;
		reduce();
		return *this;
	}
	float as_float() {
		return static_cast<float>(numerator) / denominator;
	}
	double as_double() {
		return static_cast<double>(numerator) / denominator;
	}
	long double as_long_double() {
		return static_cast<long double>(numerator) /
		       denominator;
	}
	void assign(int num, int den) {
		numerator = num;
		denominator = den;
		reduce();
	}
	void reduce() {
		assert(denominator != 0);
		if (denominator < 0) {
			denominator = -denominator;
			numerator = -numerator;
		}
		int div {gcd(numerator, denominator)};
		numerator = numerator / div;
		denominator = denominator / div;
	}
	int numerator;
	int denominator
};
rational abs(rational const& r) {
	return rational {std::abs(r.numerator), r.denominator};
}
rational operator-(rational const& r) {
	return rational {-r.numerator, r.denominator};
}
rational operator-(rational const& r) {
	return rational {-r.numerator, r.denominator};
}
rational operator-(rational const& lhs, rational const& rhs) {
	return rational {lhs.numerator * rhs.denominator - rhs.numerator * lhs.denominator,
	                 lhs.denominator * rhs.denominator
	                };
}
rational operator*(rational const& lhs, rational const& rhs) {
	return rational {lhs.numerator * rhs.numerator, lhs.denominator * rhs.denominator};
}
rational operator/(rational const& lhs, rational const& rhs) {
	return rational {lhs.numerator * rhs.denominator, lhs.denominator * rhs.numerator};
}
bool operator==(rational const& a, rational const& b) {
	return a.numerator == b.numerator and a.denominator == b.denominator;
}
inline bool operator!=(rational const& a, rational const& b) {
	return not (a == b);
}
bool operator<(rational const& a, rational const& b) {
	return a.numerator * b.denominator < b.numerator * a.denominator;
}
inline bool operator<=(rational const& a, rational const& b) {
	return not (b < a);
}
inline bool operator>(rational const& a, rational const& b) {
	return b < a;
}
inline bool operator>=(rational const& a, rational const& b) {
	return not (b > a);
}
std::istream& operator>>(std::istream& in, rational& rat) {
	int n {0}, d {0};
	char sep {'\0'};
	if (not (in >> n >> sep))
// Error reading the numerator or the separator character.
		in.setstate(in.failbit);
	else if (sep != '/') {
// Push sep back into the input stream, so the next input operation
// will read it.
		in.unget();
		rat.assign(n, 1);
	} else if (in >> d)
// Successfully read numerator, separator, and denominator.
		rat.assign(n, d);
	else
// Error reading denominator.
		in.setstate(in.failbit);
	return in;
}
/// Write a rational numbers.
/// Format is @em numerator @c / @em denominator.
std::ostream& operator<<(std::ostream& out, rational const& rat) {
	std::ostringstream tmp {};
	tmp << rat.numerator << '/' << rat.denominator;
	out << tmp.str();
	return out;
}

int main() {
    // ���Թ��캯��
    rational r1(1, 2); // 1/2
    rational r2 = r1;  // Ӧ�ø��� r1 ��ֵ��Ҳ�� 1/2
    assert(r1 == r2);  // ��� r1 �� r2 �Ƿ����

    // ���Ը�ֵ�����
    rational r3;
    r3 = r1; // �� r1 ��ֵ���� r3
    assert(r3 == r1);  // ��� r3 �Ƿ��� r1 ���

    // ���Ծ���ֵ
    rational r4 = -r1; // -1/2
    rational r5 = abs(r4); // Ӧ�ûָ�Ϊ 1/2
    assert(r5 == r1);  // ��� r5 �Ƿ��� r1 ���

    // ������������
    rational r6 = r1 + r2; // 1/2 + 1/2 = 1
    assert(r6.numerator == 1);  // ��� r6 �Ƿ�Ϊ 1
    rational r7 = r1 - r4; // 1/2 - (-1/2) = 1
    assert(r7.numerator == 1);  // ��� r7 �Ƿ�Ϊ 1
    rational r8 = r1 * r2; // 1/2 * 1/2 = 1/4
    assert(r8.numerator == 1 && r8.denominator == 4);  // ��� r8 �Ƿ�Ϊ 1/4
    rational r9 = r1 / r2; // 1/2 / 1/2 = 1
    assert(r9.numerator == 1);  // ��� r9 �Ƿ�Ϊ 1

    // ���ԱȽ������
    assert(r1 == r2);  // ��� r1 �� r2 �Ƿ����
    assert(r1 != r3);  // ��� r1 �� r3 �Ƿ���ȣ��������д��Ӧ��ʹ�� assert(r1 != r4);
    assert(r1 < r9);   // ��� r1 �Ƿ�С�� r9���������д��Ӧ��ʹ�� assert(r1 < r8);
    assert(r8 > r1);   // ��� r8 �Ƿ���� r1

    // �����������
    std::istringstream input("3/4");
    rational r10;
    input >> r10;
    std::ostringstream output;
    output << r10;
    assert(output.str() == "3/4");  // �������ַ����Ƿ�Ϊ "3/4"

    // ���� as_float, as_double, as_long_double
    float f = r1.as_float();
    double d = r1.as_double();
    long double ld = r1.as_long_double();
    assert(f == 0.5f);  // ��� f �Ƿ�Ϊ 0.5
    assert(d == 0.5);   // ��� d �Ƿ�Ϊ 0.5
    assert(ld == 0.5L); // ��� ld �Ƿ�Ϊ 0.5

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}

