struct point {
	point()
		: point {0.0, 0.0} //默认构造函数
	{}
	point(double x, double y) //参数化构造函数: 这是一个参数化构造函数，它接受两个 double 类型的参数 x 和 y，
	//							并将它们分别用于初始化成员变量 x_ 和 y_。这种构造函数用于创建一个具有指定坐标的点。
		: x_ {x}, y_ {y} 
	{}
	point(point const& pt) //拷贝构造函数: 这是拷贝构造函数，它接受一个 point 类型引用参数 pt，/
						//并通过成员初始化列表调用参数化构造函数来初始化当前对象的 x_ 和 y_ 成员变量。拷贝构造函数用于创建一个已存在 point 对象的副本。
		: point {pt.x_, pt.y_}
	{}
	double x_;
	double y_;
}

