//����1����0��1�ַ���ɵĶ��������ַ�������ת����ʮ��������
#include <iostream> 
#include <string>
#include <algorithm>
using namespace std;
string s, ans;
int main() {
	cin>>s;
	for (int i = s.size(); i > 0; i -= 4) {
		int t = 0;
		for (int j = max(0, i - 4); j < i; j++) 
			t = t * 2 + (s[j] - '0');
		if (t < 10) ans = char(t + '0') + ans;
		else ans = char ('A' + t - 10) + ans;
	}
	cout<<ans<<endl;
	return 0; 
}

