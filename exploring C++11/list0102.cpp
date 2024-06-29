///����ĸ˳��Ա�׼�����������
///��ȡ�ı��У������������Ȼ�󽫽����ӡ����׼�����
///��������������ļ�����Ӹ��ļ��ж�ȡ�����򣬶�ȡ��
///��׼���롣�������붼�洢���ڴ��У����Բ�Ҫ����
///���볬������RAM�������ļ��йء�
///
///�Ƚ�ʹ�����������������������ã���Ĭ�ϵ�δ������������
///�����������û�������������ã���Ϊ�������á�
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <locale>
#include <string>
#include <vector>
using namespace std;
//һ��C++ģ��ṹ�� text �Ķ��壬���̳��� basic_string<C> ���͡�
//basic_string ��C++��׼���е�һ��ģ����
template <class C>//ģ������
struct text : basic_string<C> { //�̳�����
	text() : text {""} {} //Ĭ�Ϲ��캯��
	//C++��char const * ��const char* ����д�����������ǵȼ۵ģ����������Ὣ������Ϊָ�������ַ�ָ�롣
	text(char const * s) : basic_string<C>(s) {} //�ַ������������캯��
	text(text&&) = default; //�ƶ����캯��
	text& operator=(text const &) = default; //���Ƹ�ֵ�����
	text& operator=(text&&) = default; //�ƶ���ֵ�����
};

template <class Ch>
auto read(basic_istream<Ch>& in)  -> vector<text<Ch>> {
	vector<text<Ch>> result;
	text<Ch> line;
	while (getline(in, line))
		result.push_back(line) ;
	return result;
}

int main(int argc, char * argv[]) {
	try {
		//��������޷��ָ����������
		cin.exceptions(ios_base::badbit);
		//��1���֡��������ȫ�����ݶ����ı�����������������ļ���
//���Ǹ��ļ������򣬶�ȡ��׼���롣
		vector<text<char>> text;
		if (argc < 2) text = read(cin);
		else {
			ifstream in(argv[1]);
			if (not in) {
				perror(argv[1]);
				return EXIT_FAILURE;
			}
			text = read(in)
		}
		//��2���֡����ı���������������ڵڶ����������Ա�����
		//�����������ã��Կ�������˳��û��������
		//������ʹ��Ĭ���������ã��Ӳ���ϵͳ��ã�
		locale const& loc { //�����������ú�����:
			locale(argc >= 3 ? argv[2] : "")
		} ;
		//����ṩ�˵ڶ��������в�������ʹ�øò�����Ϊ�������õ����ƣ����û���ṩ����ʹ�ÿ��ַ������⽫ʹ��Ĭ�ϵ��������á�
		collate<char> const& collate(use_facet<collate<char>>(loc));
		sort(text.begin(), text.end(), [&collate](
			tring const& a, string const & b) {
			return collate.compare(a.data(), a.data() + a.size(), b.data(), b.data() + b.size()) < 0;
		}) ;
		for (auto const & line : text)
			cout<<line<<'\n';
	}
	catch(exception& ex) { //�쳣����:
		cerr<<"Caught exception: " <<ex.what()<<'\n';
		cerr<<"terminating program.\n";
		exit(EXIT_FAILURE);
	}
	catch(...) { //δ֪�쳣����:
		cerr<<"Caught unknown exception type. \nTerminatiine program.\n";
		exit(EXIT_FAILURE);
	}
	return 0;
}

