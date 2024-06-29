#include <iostream>
using namespace std;
template<class T, class U>
U input_sum(istream& in) {
	T x{};
	U sum{0};
	while (in>>x) 
		sum += x;
	return sum;
}
int main() {
	long sum {input_sum<int, long>(cin)};
	cout<<sum<<'\n';
	return 0;
}

