template<class T>
struct pair<T, void> {
	typedef T first_type;
	typedef void second_type;
	T first;
	pair() = default; //默认构造函数的声明
	pair(pair const&) = default; //这是复制构造函数的声明
	pair(T const& first); //是构造函数的声明，它接受一个类型为T的引用作为参数，用于初始化成员变量first。
	template<class T2>
	pair(pair<T2, void> const& other); //是构造函数的声明，它接受一个类型为pair<T2, void>的常量引用作为参数。这个构造函数允许从其他类型的pair（其第二个元素类型为void）构造当前类型的pair。
};
