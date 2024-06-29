#include "rational.hpp"
int main() {
	rational<int> little{};
	rational<long> big{};
	big = little;
}
