//数字加密。输入2个正整数A和B，计算出A除B的值，
//按精确到小数点5位输出。但为了保密需要，每位的数字都经过了转换，
//数字0变成字符'A'，数字1变成字符'B'，…，数字9变成字符'J'等。
//输入格式：2个整数A和B，范围都在[1…10000]。
//输出格式：输出加密后的浮点数，精度为小数点后5位。
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
