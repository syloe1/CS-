//�ж��ǲ������� 
#include <iostream>

using namespace std;
int main()  {
	int y; cin>>y;
	if ((y % 4 == 0 && y % 100 != 0) || y % 4 == 0) 
		cout<<"����"<<endl;
	else cout<<"ƽ��" <<endl;
	return 0;
}
