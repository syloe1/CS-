#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
template<class InputIter>
typename std::iterator_traits<InputIter>::difference_type
index_of(InputIter first, InputIter last,
         typename std::iterator_traits<InputIter>::value_type const& value) {
	InputIter iter {std::find(first, last, value)};
	if (iter == last)
		return -1;
	else
		return std::distance(first, iter);
}
template<class T>
bool is_last(T const& container, typename T::value_type const& value) {
	return index_of(container.begin(), container.end(), value) ==
	       container.size() - 1;
}
int main() {
	std::vector<int> data {};
	if (is_last(data, 10))
		std::cout << "10 is the last item in data\n";
}
