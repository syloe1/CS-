#include <iostream>
#include <string>
class work {
	public:
		work() = default;
		work(work const&) = default;
		work(std::string const& id, std::string const& title) : id_ {id}, title_ {title} {}
		virtual ~work() {} //虚析构函数：当一个类有一个或多个虚函数时，它的析构函数也应该声明为虚函数。
		//这确保了当通过基类的指针或引用删除一个对象时，正确的析构函数将被调用
		std::string const& id() const {
			return id_;
		}
		std::string const& title() const {
			return title_;
		}
		virtual void print(std::ostream&) const {} //声明虚函数：在基类中，你通过在函数声明后面添加virtual关键字来声明一个虚函数。这告诉编译器，这个函数可以在派生类中被重写。
	private:
		std::string id_;
		std::string title_;
};
class book : public work {
	public:
		book() : work {}, author_ {}, pubyear_ {0} {}
		book(book const&) = default;
		book(std::string const& id, std::string const& title, std::string const& author,
		     int pubyear)
			: work {id, title}, author_ {author}, pubyear_ {pubyear}
		{}
		std::string const& author() const {
			return author_;
		}
		int pubyear() const {
			return pubyear_;
		}
		void print(std::ostream& out) //重写虚函数：在派生类中，你可以通过提供与基类中虚函数具有相同签名的函数来重写它。你需要在函数后面添加override关键字，
		//这是一个很好的实践，因为它可以帮助编译器检查你是否真的重写了一个虚函数。
		const override {
			out << author() << ", " << title() << ", " << pubyear() << ".";
		}
	private:
		std::string author_;
		int pubyear_; ///< year of publication
};
class periodical : public work {
	public:
		periodical() : work {}, volume_ {0}, number_ {0}, date_ {} {}
		periodical(periodical const&) = default;
		periodical(std::string const& id, std::string const& title, int volume,
		           int number,
		           std::string const& date)
			: work {id, title}, volume_ {volume}, number_ {number}, date_ {date}
		{}
		int volume() const {
			return volume_;
		}
		int number() const {
			return number_;
		}
		std::string const& date() const {
			return date_;
		}
		void print(std::ostream& out)
		const override {
			out << title() << ", " << volume() << '(' << number() << "), " <<
			    date() << ".";
		}
	private:
		int volume_; ///< volume number
		int number_; ///< issue number
		std::string date_; ///< publication date
};
void showoff(work const& w) {
	w.print(std::cout);
	std::cout << '\n';
}
std::ostream& operator<<(std::ostream& out, work const& w) {
	w.print(out);
	return out;
}
int main() {
	book sc {"1", "The Sun Also Crashes", "Ernest Lemmingway", 2000};
	book ecpp {"2", "Exploring C++", "Ray Lischner", 2013};
	periodical pop {"3", "Popular C++", 13, 42, "January 1, 2000"};
	periodical today {"4", "C++ Today", 1, 1, "January 13, 1984"};
	showoff(sc);
	showoff(ecpp);
	showoff(pop);
	showoff(today);
}
