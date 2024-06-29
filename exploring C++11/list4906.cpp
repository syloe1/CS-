template<class T>
rational<T>& rational<T>::operator/=(ration const& rhs) {
	if (rhs.numerator() == T{}) 
		throw zero_denominator("divide by zero") ;
	numerator_ *= rhs.denominator();
	denominator_ *= rhs.numerator();
	if (denominator_ < T{}) 
	{
		denominator_ = -denominator_;
		numerator_ = -numerator_; 
	}
	reduce();
	return *this;
}
