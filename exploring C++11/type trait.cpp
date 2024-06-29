template<class T>
typename std::remove_reference<T>::type&& //这是函数的返回类型
 move(T&& t) noexcept {
	return static_cast<typename std::remove_reference<T>::type&&>(t);
}
