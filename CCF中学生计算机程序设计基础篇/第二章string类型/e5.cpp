//提取整数。有1行由小写字母和数字组成的字符串，请求出字符串处理—
//string类型其中所有数的和。
//输入格式：一个字符串，长度小于100000。输出格式：输出一个整数。数据保证答案不超过2^62。
//输入样例：  ab123cde45enf  输出样例：  168
#include <iostream>
#include <string>
using namespace std;
string s;
long long ans = 0;
int main() {
	cin>>s;
	for (int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			long long t = 0;
			for (; i < s.size() && '0' <= s[i] && s[i] <= '9'; i++)
				t = t * 10 + (s[i] - '0');
			ans += t;
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
