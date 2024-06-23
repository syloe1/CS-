/*
Blah数集。大数学家高斯小时候偶然间发现一种有趣的自
然数集合Blah，对应以a为基的集合Ba定义如下：
（1）a是集合Ba的基，且a是Ba的第一个元素。
（2）如果x在集合Ba中，则2x+1和3x+1也都在集合Ba中。
（3）没有其他元素在集合Ba中了。
现在小高斯想知道如果将集合Ba中元素按照升序排列，第n个元素会
是多少
*/
#include <iostream> 
#include <algorithm>
using namespace std;
const int N = 1000100;
long long q[N];
int a, n;
void work(int a, int n) {
	int rear = 2;
	q[1] = a;
	int two = 1, three = 1;
	while (rear <= n) {
		long long t1 = q[two] * 2 + 1, t2 = q[three] * 3 + 1;
		int t = min(t1, t2);
		if (t1 < t2) {
			two++;
		} else three++;
		if (t == q[rear - 1]) continue;
		q[rear++] = t;
	}
	cout<<q[n]<<endl;
}
int main() {
	while (cin>>a>>n) work(a, n);
	return 0;
}
