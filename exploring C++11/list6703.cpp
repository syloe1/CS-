template<>
class iterator_advancer<std::random_access_iterator_tag> {  //这里定义了一个名为 iterator_advancer 的类，它特化于 std::random_access_iterator_tag 类型。
	public:
		template<class RandomIter, class Distance>
		void operator()(RandomIter& iter, Distance distance) {
			trace("iterator_advancer<random_access_iterator_tag>");
			iter += distance;
		}
};
