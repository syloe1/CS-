#include <cstdio>
#include <fstream>
#include <iostream>
int main() {
	std::ifstream in {"2.in"};
	if (not in)
		std::perror("2.in");
	else {
		std::ofstream out {"2.out"};
		if (not out)
			std::perror("2.out");
		else {
			int x {};
			while (in >> x)
				out << x << '\n';
			out.close();
			in.close();
		}
	}
	return 0;
}

