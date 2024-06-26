#include <algorithm>
#include <iostream>
#include <iterator>
#include <locale>
#include <string>
template<class Char>
bool non_letter(Char ch) {
	return not std::isalpha(ch, std::locale {});
}
/** Convert to lowercase.
 * Use a canonical form by converting to uppercase first,
 * and then to lowercase.
 * @param ch the character to test
 * @return the character converted to lowercase
 */
template<class Char>
Char lowercase(Char ch) {
	return std::tolower(ch, std::locale {});
}
/** Compare two characters without regard to case. */
template<class Char>
bool same_char(Char a, Char b) {
	return lowercase(a) == lowercase(b);
}
