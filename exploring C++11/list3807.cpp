class work {
	public:
		work() = default;
		work(work const&) = default; //���ƹ��캯��:
		work(std::string const& id, std::string const& title) : id_(id), title_(title) {} //��ʼ���б��캯��
		virtual ~work() {}
		std::string const& id() const {  //id ��Ա����: ������ id_ �ĳ������� 
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
