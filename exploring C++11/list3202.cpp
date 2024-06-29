rational& operator=(rational const& that) {
	this->numerator = that.numerator;
	this->denominator = that.denominator;
	reduce();
	return *this;
}
