#include <algorithm>
#include <iostream>
#include <locale>
bool is_alpha(char ch) {
	return std::isalpha(ch, std::locale {});
}
bool is_alpha(std::string const& str) {
	for (char ch : str)
		if (not is_alpha(ch))
			return false;
	return true;
}
char to_lower(char ch) {
	return std::tolower(ch, std::locale {});
}
/*
std::string to_lower(std::string str) {
	for (char& ch : str)
		ch = to_lower(ch);
	return str;
}
/*
std::string to_lower(std::string str)
{
 std::transform(str.begin(), str.end(), str.begin(), to_lower);
 return str;
}
*/
std::string to_lower(std::string str) {
	std::transform(str.begin(), str.end(), str.begin(),
	               static_cast<char (*)(char)>(to_lower)); //使用 static_cast<char (*)(char)> 强制类型转换
	return str;
}

char to_upper(char ch) {
	return std::toupper(ch, std::locale {});
}
std::string to_upper(std::string str) {
	for (char& ch : str)
		ch = to_upper(ch);
	return str;
}
int main() {
	std::string str {};
	while (std::cin >> str) {
		if (is_alpha(str))
			std::cout << "alpha\n";
		else
			std::cout << "not alpha\n";
		std::cout << "lower: " << to_lower(str) << "\nupper: " << to_upper(str) << '\n';
	}
}

