template<class T>
struct pair<T, void> {
	typedef T first_type;
	typedef void second_type;
	T first;
	pair() = default; //Ĭ�Ϲ��캯��������
	pair(pair const&) = default; //���Ǹ��ƹ��캯��������
	pair(T const& first); //�ǹ��캯����������������һ������ΪT��������Ϊ���������ڳ�ʼ����Ա����first��
	template<class T2>
	pair(pair<T2, void> const& other); //�ǹ��캯����������������һ������Ϊpair<T2, void>�ĳ���������Ϊ������������캯��������������͵�pair����ڶ���Ԫ������Ϊvoid�����쵱ǰ���͵�pair��
};
