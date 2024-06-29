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
	vector<int> cop{source}; //��������˸��ƹ��캯��
	print(cop);
	vector<int> mov(move(source)); //����������ƶ����캯��
	print(mov);
	print(source);
	return 0;
}

