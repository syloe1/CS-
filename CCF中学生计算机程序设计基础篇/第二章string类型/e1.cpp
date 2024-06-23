//过滤多余的空格。
//hello     world.This  is c language
//hello world. This is c language
#include <iostream> 
#include <string>
using namespace std;
int main() {
	string s, t;
	cin>>s;
	
	while (cin>>t) {
		s += ' ' + t;
	}
	cout<<s<<endl;
	system("pause");
	return 0;
}
