template <class T>
class point {
	public:
		point(T x, T y) : x_{x}, y_{y}  {}
		T x() const {return x_; }
		T y() const {return y_; }
		void move_to(T x, T y);
		void move_by(T x, T y);
	private:
		T x_, y_;
};
template<class T>
void point<T>::move_to(T x, T y) {
	x_ = x;
	y_ = y;
}
template<class T>
void point<T>::move)by(T x, T y) {
	x_ += x
	y_ += y;
}
