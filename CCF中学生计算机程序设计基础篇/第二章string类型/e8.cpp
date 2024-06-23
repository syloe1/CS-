//有N个人的姓名，请把他们按姓名的字典序排序输出。
//输入格式：第1行，有一个整数N，N的范围是[1…10000]；下面第
//2 行到第N+1行，每行是1个姓名。姓名由不超过50个小写字母组成。
//输出格式：N行，每行一个姓名。
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n;
string a[100000];
int main() {
	cin>>n;
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		cout<<a[i]<<endl;
	}
	return 0;
}
