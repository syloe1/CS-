#include <iostream>
#include <utility>
#include <vector>
using namespace std;
void print(vector<int> const& vector) {
	cout<<"{ ";
	for (int i : vector)  cout<<i<<" ";
	cout<<"}\n";
}

int main() {
	vector<int> source{1, 2, 3};
	print(source);
	vector<int> cop{source}; //这里调用了复制构造函数
	print(cop);
	vector<int> mov(move(source)); //这里调用了移动构造函数
	print(mov);
	print(source);
	return 0;
}

