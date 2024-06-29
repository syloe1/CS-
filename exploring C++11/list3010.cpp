#include <iostream>
using namespace std;

ration operator* (ration const & rat, int mult) {
	return rational{rat.numerator * mult, rat.denominator};
}
inline ration operator*(int mult, ration const & rat) {
	return rat * mult;
}


int main() {
	return 0;
}

