// 预处理指令，防止头文件被多次包含
#ifndef RATIONAL_HPP_
#define RATIONAL_HPP_

// 定义一个模板类rational，用于表示有理数
template<class T>
class rational {
public:
    // 定义类型别名value_type，用于表示有理数的数值类型
    typedef T value_type;

    // 构造函数
    rational() : rational{0} {} // 默认构造函数，初始化为0
    rational(T num) : numerator_{num}, denominator_{1} {} // 构造函数，初始化分子和分母

    // 带有两个参数的构造函数，需要模板参数T的特化
    rational(T num, T den);

    // 赋值函数，用于设置有理数的分子和分母
    void assign(T num, T den);

    // 转换函数模板，将有理数转换为其他类型U
    template<class U>
    U convert() const {
        return static_cast<U>(numerator_) / static_cast<U>(denominator_);
    }

    // 获取分子的成员函数
    T numerator() const { return numerator_; }

    // 获取分母的成员函数
    T denominator() const { return denominator_; }

private:
    // 私有成员函数，用于简化有理数
    void reduce();

    // 私有成员变量，存储分子和分母
    T numerator_;
    T denominator_;
};

// 带有两个参数的构造函数的实现
template<class T>
rational<T>::rational(T num, T den)
    : numerator_{num}, denominator_{den} {
    reduce();
}

// 赋值函数的实现
template<class T>
void rational<T>::assign(T num, T den) {
    numerator_ = num;
    denominator_ = den;
    reduce();
}

// 重载==运算符，比较两个有理数是否相等
template<class T>
bool operator==(const rational<T>& a, const rational<T>& b) {
    return a.numerator() == b.numerator() && a.denominator() == b.denominator();
}

// 重载!=运算符，比较两个有理数是否不相等
template<class T>
inline bool operator!=(const rational<T>& a, const rational<T>& b) {
    return !(a == b);
}

#endif // RATIONAL_HPP_
