//使用packaged的accumulate并行版本
template<typename Iterator, typename T>
struct accumulate_block {
	T operator()(Iterator first, Iterator last, T& result) {
		result = std::accumulate(first, last, result);
	}
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init) {
	auto length = std::distance(first, last);
	if (!length) return init;

	const unsigned long min_per_thread = 25;
	unsigned long const max_threads = (length + min_per_thread - 1) / min_per_thread;
	unsigned long const hardware_threads = std::thread::hardware_concurrency();
	unsigned long const num_threads = std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);

	unsigned long const block_size = length / num_threads;
	std::vector<future<T>> futures(num_threads - 1);
	std::vector<std::thread> threads(num_threads - 1);

	Iterator block_start = first;
	for (unsigned long i = 0; i < num_threads - 1; ++i) {
		Iterator block_end = block_start;
		std::advance(block_end, block_size);
		std::packaged_task<T(Iterator, Iterator)> task (
		    accumulate_block<Iterator, T>());
		futures[i] = task.get_future();
		thread[i] = thread(move(task), block_start, block_end);
		block_start = block_end;
		)
	}

	T last_result = accumulate_block() {
		block_start, last
	};
	for_each(threads.begin(), threads.end(),
	         mem_fn(&std::thread::join()));
	T result = init;
	for (unsigned long i = 0; i < (num_threads - 1); i++) {
		result += futures[i].get();
	}
	result += last_result;
	return result;
}
