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
		auto lowercase = [](char ch) { //����һ���ڲ��� lambda ���ʽ�����ڽ��ַ�ת��ΪСд�����������ⲿ�� locale ���󣬲�ʹ������ִ��ת����
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
