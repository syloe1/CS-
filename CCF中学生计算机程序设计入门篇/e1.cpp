//判断是不是闰年 
#include <iostream>

using namespace std;
int main()  {
	int y; cin>>y;
	if ((y % 4 == 0 && y % 100 != 0) || y % 4 == 0) 
		cout<<"闰年"<<endl;
	else cout<<"平年" <<endl;
	return 0;
}
