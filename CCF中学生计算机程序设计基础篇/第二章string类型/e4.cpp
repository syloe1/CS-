//ժ¼���֡� ����1������ĸ���ַ�'#'��ɵ��ַ����� ��֤�ַ�'#'����ż�Ρ�
//��ǰ��󿴣� ÿ����'#' �ַ�֮����ַ�����Ҫժ¼�����֣� ���̰�ժ¼���ַ������������
#include <iostream>
#include <string>
using namespace std;
int main() {
	string s,ans;
	int p;
	cin >> s;
	for(int i=0; i<s.size(); i++)
		if(s[i]=='#') { // �ҵ�ǰ���#λ��
			p=i+1;// Ҫժ¼�Ŀ�ʼλ��
			for(i++; s[i]!='#'; i++); //�ҵ������#λ��
			ans+= s.substr(p,i-p); //ȡ����Σ����ӵ�ans
		}
	cout << ans <<endl;
	return 0;
}
