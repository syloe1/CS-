#include <algorithm>
#include <iostream>
#include <iterator>
#include <locale>
#include <string>
using namespace std;
bool is_palindrome(string str) {
	string::iterator end {std::remove_if(str.begin(), str.end(), [](char ch) {
		return not isalpha(ch, locale());
	})
	                     };
	string rev {str.begin(), end};
	reverse(rev.begin(), rev.end());
	return not rev.empty() and equal(str.begin(), end, rev.begin(), [](char a, char b) {
		auto lowercase = [](char ch) { //这是一个内部的 lambda 表达式，用于将字符转换为小写。它捕获了外部的 locale 对象，并使用它来执行转换。
			return tolower(ch,  locale());
		};
		return lowercase(a) == lowercase(b);
	});
}
int main() {
	locale::global(locale {""});
	cin.imbue(locale {});
	cout.imbue(locale {});
	string line{};
	while (getline(cin, line)) 
		if (is_palindrome(line)) {
			cout<<line<<'\n';
		}
	return 0;
}
