//使用async来将参数传递给函数
 #include <string>
#include <future>

struct X {
    void foo(int, std::string const&);
    std::string bar(std::string const&);
};
X xl 
// 假设 p 是 x 类型的引用
auto f1 = std::async(&x::foo, &p, 42, "hello");
auto f2 = std::async(&x::bar, p, "goodbye");

struct Y {
    double operator()(double);
};
Y y;
// 假设 tmpy 是从 Y() 移动构造的
 auto f3 = std::async(Y(), 3.141);
auto f4 = std::async(std::ref(y), 2.718);

vo
 X baz(x&);
std::async(std::ref(x), baz);

class move_only {
public:
    move_only();
    move_only(move_only&&);
    move_only(move_only const&) = delete;
    move_only& operator=(move_only&&);
    move_only& operator=(move_only const&) = delete;
    void operator()();
};

// 假设 tmp 是从 std::move(move_only()) 构造的
// auto f5 = std::async(tmp);
auto f5 = std::async(move_only());
