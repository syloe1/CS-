#include <iostream>
using namespace std;

struct rational {
	float as_float() {
		return static_cast<float>(numerator) / denominator;
	}
	double as_double() {
		return numerator / static_cast<double>(denominator);
	}
	long double as_long_double() {
		return static_cast<long double>(numerator) /
		       static_cast<long double>(denominator);
	}


	int main() {
		return 0;
	}

