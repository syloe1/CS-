//ʹ��async�����������ݸ�����
 #include <string>
#include <future>

struct X {
    void foo(int, std::string const&);
    std::string bar(std::string const&);
};
X xl 
// ���� p �� x ���͵�����
auto f1 = std::async(&x::foo, &p, 42, "hello");
auto f2 = std::async(&x::bar, p, "goodbye");

struct Y {
    double operator()(double);
};
Y y;
// ���� tmpy �Ǵ� Y() �ƶ������
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

// ���� tmp �Ǵ� std::move(move_only()) �����
// auto f5 = std::async(tmp);
auto f5 = std::async(move_only());
