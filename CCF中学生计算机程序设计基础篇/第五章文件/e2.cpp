/*
文件结束。已知文件中有不超过1000个的正整数，请计算
它们的和（保证答案在10000以内）。
输入格式（文件sum.in）： 1行，多个整数，范围是 [1，1000]。
输出格式（文件sum.out）：输出一个整数。
输入样例：
10 5 6 9
输出样例：
  30
*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("sum.in");
ofstream fout("sum.out");
int x, sum;
int main() {
	sum = 0;
	//while (!fin.eof()) 没有文件结束就循环 
	while (fin>>x) {
		sum += x;
	}
	fout<<sum<<endl;
	return 0;
}
