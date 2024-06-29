rational& operator=(int num) {
	this->numerator = num;
	this->denominator = 1; // no need to call reduce()
	return *this;
}
