struct rational {
	rational(int num, int den) //���캯�� 
		: numerator {num}, denominator {den} {
		reduce();
	}
	rational& operator=(rational const& rhs) { //��ֵ��������� 
		numerator = rhs.numerator;
		denominator = rhs.denominator;
		reduce();
		return *this;
	}
	int numerator;
	int denominator;
}
