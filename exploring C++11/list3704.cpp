#include <iostream>
#include <vector>
class base {
	public:
		base(int value) : value_ {value} { std::cout << "base(" << value << ")\n"; }
		base() : base {0} { std::cout << "base()\n"; }
		base(base const& copy)
			: value_ {copy.value_}
		{ std::cout << "copy base(" << value_ << ")\n"; }
		~base() {
			std::cout << "~base(" << value_ << ")\n";
		}
		int value() const {
			return value_;
		}
		base& operator++() {
			++value_;
			return *this; // 返回当前对象的引用
		}
	private:
		int value_;
};
class derived : public base {
	public:
		derived(int value): base {value} { std::cout << "derived(" << value << ")\n"; } //带参数构造函数 
		derived() : base {} { std::cout << "derived()\n"; }
		derived(derived const& copy) //拷贝构造函数 
			: base {copy}
		{ std::cout << "copy derived(" << value() << "\n"; }
		~derived() {
			std::cout << "~derived(" << value() << ")\n";
		}
};
derived make_derived() {
	return derived {42};
}
base increment(base b) {
	++b;
	return b;
}
void increment_reference(base& b) {
	++b;
}
int main() {
	derived d {make_derived()};
	base b {increment(d)};
	increment_reference(d);
	increment_reference(b);
	derived a(d.value() + b.value());
}
