/*
Blah����������ѧ�Ҹ�˹Сʱ��żȻ�䷢��һ����Ȥ����
Ȼ������Blah����Ӧ��aΪ���ļ���Ba�������£�
��1��a�Ǽ���Ba�Ļ�����a��Ba�ĵ�һ��Ԫ�ء�
��2�����x�ڼ���Ba�У���2x+1��3x+1Ҳ���ڼ���Ba�С�
��3��û������Ԫ���ڼ���Ba���ˡ�
����С��˹��֪�����������Ba��Ԫ�ذ����������У���n��Ԫ�ػ�
�Ƕ���
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
