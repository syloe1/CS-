#include <iostream>
#include <string>
int main() {
	std::cout << "How old are you? ";
	int age {};
	std::cin >> age;
	std::cout << "What is your name? ";
	std::string name {};
	std::cin >> name;
	std::cout << "Good-bye, " << name << ". You are " << age << " year";
	if (age != 1)
		std::cout << 's';
	std::cout << " old.\n";
	return 0;
}
