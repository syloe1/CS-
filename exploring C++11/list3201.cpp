struct rational {
	rational(int num, int den) //构造函数 
		: numerator {num}, denominator {den} {
		reduce();
	}
	rational& operator=(rational const& rhs) { //赋值运算符重载 
		numerator = rhs.numerator;
		denominator = rhs.denominator;
		reduce();
		return *this;
	}
	int numerator;
	int denominator;
}
