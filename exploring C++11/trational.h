// Ԥ����ָ���ֹͷ�ļ�����ΰ���
#ifndef RATIONAL_HPP_
#define RATIONAL_HPP_

// ����һ��ģ����rational�����ڱ�ʾ������
template<class T>
class rational {
public:
    // �������ͱ���value_type�����ڱ�ʾ����������ֵ����
    typedef T value_type;

    // ���캯��
    rational() : rational{0} {} // Ĭ�Ϲ��캯������ʼ��Ϊ0
    rational(T num) : numerator_{num}, denominator_{1} {} // ���캯������ʼ�����Ӻͷ�ĸ

    // �������������Ĺ��캯������Ҫģ�����T���ػ�
    rational(T num, T den);

    // ��ֵ���������������������ķ��Ӻͷ�ĸ
    void assign(T num, T den);

    // ת������ģ�壬��������ת��Ϊ��������U
    template<class U>
    U convert() const {
        return static_cast<U>(numerator_) / static_cast<U>(denominator_);
    }

    // ��ȡ���ӵĳ�Ա����
    T numerator() const { return numerator_; }

    // ��ȡ��ĸ�ĳ�Ա����
    T denominator() const { return denominator_; }

private:
    // ˽�г�Ա���������ڼ�������
    void reduce();

    // ˽�г�Ա�������洢���Ӻͷ�ĸ
    T numerator_;
    T denominator_;
};

// �������������Ĺ��캯����ʵ��
template<class T>
rational<T>::rational(T num, T den)
    : numerator_{num}, denominator_{den} {
    reduce();
}

// ��ֵ������ʵ��
template<class T>
void rational<T>::assign(T num, T den) {
    numerator_ = num;
    denominator_ = den;
    reduce();
}

// ����==��������Ƚ������������Ƿ����
template<class T>
bool operator==(const rational<T>& a, const rational<T>& b) {
    return a.numerator() == b.numerator() && a.denominator() == b.denominator();
}

// ����!=��������Ƚ������������Ƿ����
template<class T>
inline bool operator!=(const rational<T>& a, const rational<T>& b) {
    return !(a == b);
}

#endif // RATIONAL_HPP_
