#ifndef SALESITEM_H
#define SALESITEM_H
#include <iostream>
#include <string>

class Sales_item
{
public:
	Sales_item(const std::string &book) :isbn(book), units_sold(0), revenue(0.0) {}
	Sales_item(std::istream &is) {  //在这个构造函数中，istream &is 是一个输入流的引用，它表示这个构造函数接受一个输入流作为参数。这个构造函数的作用是从输入流中读取数据，并用这些数据来初始化 Sales_item 对象的成员变量。
	is >> *this;
	 }
	friend std::istream& operator>>(std::istream &, Sales_item &);
	friend std::ostream& operator<<(std::ostream &, const Sales_item &); //声明了两个友元函数，使得这两个函数能够直接访问 Sales_item 类的私有成员，并且用于重载输入流和输出流的运算符
public:
	Sales_item & operator+=(const Sales_item&);
public:
	double avg_price() const;
	bool same_isbn(const Sales_item &rhs)const
	{
		return isbn == rhs.isbn;
	}
	Sales_item() :units_sold(0), revenue(0.0) {}
public:
	std::string isbn;
	unsigned units_sold;
	double revenue;
};

using std::istream;
using std::ostream;
// 声明运算符重载
Sales_item operator+(const Sales_item &, const Sales_item &);
inline bool operator==(const Sales_item &lhs, const Sales_item &rhs)
{
	return lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue && lhs.same_isbn(rhs);
}
inline bool operator!=(const Sales_item &lhs, const Sales_item &rhs)
{
	return !(lhs == rhs);
}

inline Sales_item & Sales_item::operator +=(const Sales_item &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
inline Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs)
{
	Sales_item ret(lhs);
	ret += rhs;
	return ret;
}
inline istream& operator>>(istream &in, Sales_item &s)
{
	double price;
	in >> s.isbn >> s.units_sold >> price;
	if (in)
		s.revenue = s.units_sold * price;
	else
		s = Sales_item();
	return in;
}
inline ostream& operator<<(ostream &out, const Sales_item &s)
{
	out << s.isbn << "\t" << s.units_sold << "\t" << s.revenue << "\t" << s.avg_price();
	return out;
}
inline double Sales_item::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}
#endif
