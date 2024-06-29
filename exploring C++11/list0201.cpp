#include <iostream>
#include <limits> 
using namespace std;
int main() {
	int min{numeric_limits<int>::max()}; //��ʼ�� min ����Ϊ int ���͵����ֵ���Ա����ҵ���һ������ֵʱ���бȽϡ�
	int max{numeric_limits<int>::min()}; //��ʼ�� max ����Ϊ int ���͵���Сֵ���Ա����ҵ���һ������ֵʱ���бȽϡ�
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
