//统计数字字符个数。 输入一行字符， 统计出其中数字字符的个数。
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
