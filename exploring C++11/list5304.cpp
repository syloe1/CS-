#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <vector>
#include "erase_less.hpp" //Listing 53-3
/// Extract items from a string and store them in a container.
template<class Container>
void read(std::string const& str, Container& cont) {
	std::istringstream in {str};
	cont.insert(cont.begin(),
	            std::istream_iterator<typename Container::value_type>(in),
	            std::istream_iterator<typename Container::value_type>());
}
/// Print items from a container to the standard output.
template<class Container>
void print(std::string const& label, Container const& cont) {
	std::cout << label;
	std::copy(cont.begin(), cont.end(),
	          std::ostream_iterator<typename Container::value_type>(std::cout, " "));
	std::cout << '\n';
}
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <vector>
#include "erase_less.hpp" //Listing 53-3
/// Extract items from a string and store them in a container.
template<class Container>
void read(std::string const& str, Container& cont) {
	std::istringstream in {str};
	cont.insert(cont.begin(),
	            std::istream_iterator<typename Container::value_type>(in),
	            std::istream_iterator<typename Container::value_type>());
}
/// Print items from a container to the standard output.
template<class Container>
void print(std::string const& label, Container const& cont) {
	std::cout << label;
	std::copy(cont.begin(), cont.end(),
	          std::ostream_iterator<typename Container::value_type>(std::cout, " "));
	std::cout << '\n';
}

