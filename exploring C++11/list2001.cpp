#include <iostream>
#include <string>
using namespace std;
void ignore_line() {
	char c{};
	while (cin.get(c) and c != '\n') {
		//empty;
	}
}
int prompted_read(string prompt) {
	cout<<prompt;
	int x{0}; cin>>x;
	ignore_line(); return x;
}
void print_result(int count, int sum) {
	if (count == 0) {
		cout<<"no data\n";
		return ;
	}
	cout<<"\ncount = "<<count;
	cout<<"\nsum = "<<sum;
	cout<<"\nmean = "<<sum / count<<'\n';
}

int main() {
	int sum {0};
	int count {0};
	while (cin) {
		int x {prompted_read("Value: ")}  ;
		if (cin) {
			sum = sum + x; ++count;
		}
	}print_result(count, sum);
	return 0;
}

