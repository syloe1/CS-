template<>
class iterator_advancer<std::random_access_iterator_tag> {  //���ﶨ����һ����Ϊ iterator_advancer ���࣬���ػ��� std::random_access_iterator_tag ���͡�
	public:
		template<class RandomIter, class Distance>
		void operator()(RandomIter& iter, Distance distance) {
			trace("iterator_advancer<random_access_iterator_tag>");
			iter += distance;
		}
};
