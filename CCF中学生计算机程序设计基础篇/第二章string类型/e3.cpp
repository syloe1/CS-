//ͳ�������ַ������� ����һ���ַ��� ͳ�Ƴ����������ַ��ĸ�����
 #include <iostream>
 #include <string>
 using namespace std;
 int main() {
 	string s; getline(cin, s);
 	int c = 0;
 	for (int i = 0; i < s.size(); i++) {
 		if ('0' <= s[i] && s[i] <= '9') {
 			c++;
		 }
	 }
	 cout<<c<<endl;
 	return 0;
 }
