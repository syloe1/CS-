template<> //��ʾģ���ػ� 
struct pair<void, void> {
	typedef void first_type;
	typedef void second_type;
	pair(pair const&) = default;
	pair() = default;
	pair& operator=(pair const&) = default;
};
