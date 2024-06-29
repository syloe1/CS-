///按字母顺序对标准输入进行排序。
///读取文本行，对其进行排序，然后将结果打印到标准输出。
///如果命令行命名文件，请从该文件中读取。否则，读取自
///标准输入。整个输入都存储在内存中，所以不要尝试
///这与超过可用RAM的输入文件有关。
///
///比较使用命令行上命名的区域设置，或默认的未命名区域设置
///如果命令行上没有命名区域设置，则为区域设置。
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <locale>
#include <string>
#include <vector>
using namespace std;
//一个C++模板结构体 text 的定义，它继承自 basic_string<C> 类型。
//basic_string 是C++标准库中的一个模板类
template <class C>//模板声明
struct text : basic_string<C> { //继承声明
	text() : text {""} {} //默认构造函数
	//C++中char const * 何const char* 两种写法在语义上是等价的，编译器都会将它们视为指向常量的字符指针。
	text(char const * s) : basic_string<C>(s) {} //字符串字面量构造函数
	text(text&&) = default; //移动构造函数
	text& operator=(text const &) = default; //复制赋值运算符
	text& operator=(text&&) = default; //移动赋值运算符
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
		//如果发生无法恢复的输入错误
		cin.exceptions(ios_base::badbit);
		//第1部分。将输入的全部内容读成文本。如果命令行命名文件，
//读那个文件。否则，读取标准输入。
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
		//第2部分。对文本进行排序。如果存在第二个命令行自变量，
		//命名区域设置，以控制排序顺序。没有命令行
		//参数，使用默认区域设置（从操作系统获得）
		locale const& loc { //设置区域设置和排序:
			locale(argc >= 3 ? argv[2] : "")
		} ;
		//如果提供了第二个命令行参数，则使用该参数作为区域设置的名称；如果没有提供，则使用空字符串，这将使用默认的区域设置。
		collate<char> const& collate(use_facet<collate<char>>(loc));
		sort(text.begin(), text.end(), [&collate](
			tring const& a, string const & b) {
			return collate.compare(a.data(), a.data() + a.size(), b.data(), b.data() + b.size()) < 0;
		}) ;
		for (auto const & line : text)
			cout<<line<<'\n';
	}
	catch(exception& ex) { //异常捕获:
		cerr<<"Caught exception: " <<ex.what()<<'\n';
		cerr<<"terminating program.\n";
		exit(EXIT_FAILURE);
	}
	catch(...) { //未知异常捕获:
		cerr<<"Caught unknown exception type. \nTerminatiine program.\n";
		exit(EXIT_FAILURE);
	}
	return 0;
}

