template<class T>
typename std::remove_reference<T>::type&& //���Ǻ����ķ�������
 move(T&& t) noexcept {
	return static_cast<typename std::remove_reference<T>::type&&>(t);
}
