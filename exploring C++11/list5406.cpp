#include <algorithm>
#include <iostream>
#include <iterator>
#include <locale>
#include <string>
#include <vector>
void sort_words(std::vector<std::string> words, std::locale loc) {
	std::sort(words.begin(), words.end(), loc);
	std::cout << loc.name() << ":\n";
	std::copy(words.begin(), words.end(),
	          std::ostream_iterator<std::string>(std::cout, "\n"));
}
int main() {
	using namespace std;
	vector<string> words {
		"circus",
		"\u00e5ngstrom", // ?ngstrom
		"\u00e7irc\u00ea", // ?irc¨º
		"angle",
		"essen",
		"ether",
		"\u00e6ther", // ?ther
		"aether",
		"e\u00dfen" // e?en
	};
	sort_words(words, locale::classic());
	sort_words(words, locale {"en_GB.utf8"}); // Great Britain
	sort_words(words, locale {"no_NO.utf8"}); // Norway

}
