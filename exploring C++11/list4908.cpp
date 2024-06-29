template<class T>
template<class U>
rational<T>& rational<T>::operator=(rational<U> const& rhs) {
	assign(rhs.numerator(), rhs.denominator());
	return *this;
}
