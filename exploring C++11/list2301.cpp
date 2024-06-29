#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
int main()
{
	vector<int> data{};
	/*
	ʹ�� std::copy �����ӱ�׼���루cin������������ data �����С�istream_iterator<int>(cin) ��һ�����������������ȡ cin �е�������istream_iterator<int>() ��һ����������������ʾ���������back_inserter(data) ��һ�����������������Ԫ�ز��뵽 data ��ĩβ��
	*/
	copy(istream_iterator<int>(cin), 
		istream_iterator<int>(),
		back_inserter(data));
	//data.begin() ��Ϊ��������������ʾ�������д�뵽 data �����Ŀ�ʼλ�á�����ζ��ԭ���޸� data �е�Ԫ�ء�

	//[](int x) { return x * 2; } ��һ�� lambda ���ʽ����������һ�������������ú�������һ������ x ��Ϊ������������ x ���� 2 �Ľ����
	transform(data.begin(), data.end(), data.begin(), [](int x) {
		return x * 2;
	});
	copy(data.begin(), data.end(), ostream_iterator<int>(cout, "\n"));
	return 0;
}
