#include <ostream> // declares the necessary << operators
#include <sstream> // declares the std::ostringstream type
std::ostream& operator<<(std::ostream& out, rational const& rat) {
	std::ostringstream tmp {};
	tmp << rat.numerator;
	if (rat.denominator != 1)
		tmp << '/' << rat.denominator;
	out << tmp.str();
	return out;
}
bool iofailure(std::istream& in) {
	return in.fail() and not in.bad();
}
int main() {
	rational r {0};
	while (std::cin) {
		if (std::cin >> r)
// Read succeeded, so no failure state is set in the stream.
			std::cout << r << '\n';
		else if (iofailure(std::cin)) {
// Only failbit is set, meaning invalid input. Clear the state,
// and then skip the rest of the input line.
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		}
	}
	if (std::cin.bad())
		std::cerr << "Unrecoverable input failure\n";
}
