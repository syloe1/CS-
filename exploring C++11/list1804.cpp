#include <iostream>
#include <locale>
#include <map>
#include <string>
int main() {
	typedef std::map<std::string, int>    count_map;
	std::locale native {""};            // get the native locale .//td::locale��һ����ʾ����������Ϣ�Ķ�������װ���Ļ��ض���ƫ�ã��������ԡ�����/�������ַ�����������������ȷ�����֡����ںͻ��ҵĸ�ʽ���Լ��ַ����ȽϺ���������Ϊ��
	std::cin.imbue(native);  //.imbue()������ std::cin���Լ�����I/O������һ����Ա���������ڸ���ָ��һ���������á�imbue ����˼�ǡ�ע�롱��������ָ���ǽ�һ���ض�����������ע�뵽���У�Ӱ���������������Ϊ��
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
