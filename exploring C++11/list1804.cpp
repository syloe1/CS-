#include <iostream>
#include <locale>
#include <map>
#include <string>
int main() {
	typedef std::map<std::string, int>    count_map;
	std::locale native {""};            // get the native locale .//td::locale是一个表示区域设置信息的对象，它封装了文化特定的偏好，例如语言、国家/地区和字符集。区域设置用于确定数字、日期和货币的格式，以及字符串比较和搜索的行为。
	std::cin.imbue(native);  //.imbue()：这是 std::cin（以及其它I/O流）的一个成员函数，用于给流指定一个区域设置。imbue 的意思是“注入”，在这里指的是将一个特定的区域设置注入到流中，影响流的输入输出行为。
	std::cout.imbue(native);            // the native locale
	count_map counts {};
	// Read words from the standard input and count the number of times
	// each word occurs.
	std::string word {};
	while (std::cin >> word) {
		// Make a copy of word, keeping only alphabetic characters.
		std::string copy {};
		for (char ch : word)
			if (std::isalnum(ch, native))
				copy.push_back(ch);
		// The "word" might be all punctuation, so the copy would be empty.
		// Don't count empty strings.
		if (not copy.empty())
			++counts[copy];
	}
	// For each word/count pair, print the word & count on one line.
	for (auto pair : counts)
		std::cout << pair.first << '\t' << pair.second << '\n';
}
