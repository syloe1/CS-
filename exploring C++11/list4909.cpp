template<class T>
template<class U>
rational<T>::ration(rational<U> const& copy) : 
numerator_{copy.numerator()}, denominator_{copy.denominator()} {}
