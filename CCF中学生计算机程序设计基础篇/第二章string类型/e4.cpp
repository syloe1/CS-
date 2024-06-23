//摘录文字。 输入1行由字母和字符'#'组成的字符串， 保证字符'#'出现偶次。
//从前向后看， 每两个'#' 字符之间的字符串是要摘录的文字， 请编程把摘录的字符串连续输出。
#include <iostream>
#include <string>
using namespace std;
int main() {
	string s,ans;
	int p;
	cin >> s;
	for(int i=0; i<s.size(); i++)
		if(s[i]=='#') { // 找到前面的#位置
			p=i+1;// 要摘录的开始位置
			for(i++; s[i]!='#'; i++); //找到后面的#位置
			ans+= s.substr(p,i-p); //取出这段，连接到ans
		}
	cout << ans <<endl;
	return 0;
}
