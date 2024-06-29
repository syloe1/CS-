#include <cmath>
#include <iostream>
template<class T>
class point2d {
public:
 point2d(T x, T y) : x_(x), y_(y) {}
 virtual ~point2d() {}
 T x() const { return x_; }
 T y() const { return y_; }
 T abs() const { return std::sqrt(x() * x() + y() * y()); }
 virtual void print(std::ostream& stream) const {
 stream << '(' << x() << ", " << y() << ')';
 }
private:
 T x_, y_;
};
template<class T>
class point3d : public point2d<T> {
public:
 point3d(T x, T y, T z) : point2d<T>(x, y), z_(z) {}
 T z() const { return z_; }
 T abs() const {
 return static_cast<T>(std::sqrt(this->x() * this->x() +
 this->y() * this->y() +
 this->z() * this->z()));
 }
 virtual void print(std::ostream& stream) const {
 stream << '(' << this->x() << ", " << this->y() << ", " << z() << ')';
 }
private:
 T z_;
};
