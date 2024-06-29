class work {
	public:
		work() = default;
		work(work const&) = default; //复制构造函数:
		work(std::string const& id, std::string const& title) : id_(id), title_(title) {} //初始化列表构造函数
		virtual ~work() {}
		std::string const& id() const {  //id 成员函数: 它返回 id_ 的常量引用 
			return id_;
		}
		std::string const& title() const {
			return title_;
		}
		virtual void print(std::ostream& out) const = 0;
	private:
		std::string id_;
		std::string title_;
};
