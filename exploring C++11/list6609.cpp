#include <string>
#include <utility>
#include "assignment_mixin.hpp" // Listing 66-8
class thing: public assignment_mixin<thing> {
	public:
		thing() : value_ {} {}
		thing(std::string&& s) : value_ {std::move(s)} {}
		void swap(thing& other) {
			value_.swap(other.value_);
		}
	private:
		std::string value_;
};
int main() {
	thing one {};
	thing two {"two"};
	one = two;
}
