//��ȡ��������1����Сд��ĸ��������ɵ��ַ�����������ַ�������
//string���������������ĺ͡�
//�����ʽ��һ���ַ���������С��100000�������ʽ�����һ�����������ݱ�֤�𰸲�����2^62��
//����������  ab123cde45enf  ���������  168
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
