//���ּ��ܡ�����2��������A��B�������A��B��ֵ��
//����ȷ��С����5λ�������Ϊ�˱�����Ҫ��ÿλ�����ֶ�������ת����
//����0����ַ�'A'������1����ַ�'B'����������9����ַ�'J'�ȡ�
//�����ʽ��2������A��B����Χ����[1��10000]��
//�����ʽ��������ܺ�ĸ�����������ΪС�����5λ��
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
using namespace std;
int a, b;
stringstream t;
string ans;
int main()  {
	cin>>a>>b;
	t<<fixed<<setprecision(5)<<double(a) /b;
	t>>ans;
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] != '.') {
			ans[i] = char(ans[i] + 'A' - '0');
		}
	}
	cout<<ans<<endl;
	return 0;
}
