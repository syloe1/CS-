#include <iostream>
#include <limits> 
using namespace std;
int main() {
	int min{numeric_limits<int>::max()}; //初始化 min 变量为 int 类型的最大值，以便在找到第一个输入值时进行比较。
	int max{numeric_limits<int>::min()}; //初始化 max 变量为 int 类型的最小值，以便在找到第一个输入值时进行比较。
	bool any{false};
	int x;
	while (cin>>x) {
		any = true;
		if (x < min) {
			min = x;
		}
		if (x > max) {
			max = x;
		}
	}
	if (any) {
		cout<<"min = "<<min<<"\nmax = "<<max<<'\n';
	}
	return 0;
}
