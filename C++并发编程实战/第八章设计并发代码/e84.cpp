//accumulate的异常安全并行版本
 #include <vector>
#include <thread>
#include <future>
#include <functional>
#include <iterator>

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init) {
    unsigned long const length = std::distance(first, last);
    if (!length)
        return init;

    unsigned long const min_per_thread = 25;
    unsigned long const max_threads = (length + min_per_thread - 1) / min_per_thread;
    unsigned long const hardware_threads = std::thread::hardware_concurrency();
    unsigned long const num_threads = std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);
    unsigned long const block_size = length / num_threads;

    std::vector<std::future<T>> futures(num_threads - 1);
    std::vector<std::thread> threads(num_threads - 1);
    join_threads joiner(threads); // Assuming join_threads is a RAII wrapper to join threads

    Iterator block_start = first;
    for (unsigned long i = 0; i < num_threads - 1; ++i) {
        Iterator block_end = block_start;
        std::advance(block_end, block_size);

        // Assuming accumulate_block is a callable that takes two Iterators and returns T
        std::packaged_task<T(Iterator, Iterator)> task(accumulate_block<Iterator, T>());
        futures[i] = task.get_future();
        threads[i] = std::thread(std::move(task), block_start, block_end);
        block_start = block_end;
    }

    T last_result = accumulate_block<Iterator, T>()(block_start, last); // Assuming accumulate_block is callable
    T result = init;
    for (unsigned long i = 0; i < num_threads - 1; ++i) {
        result += futures[i].get(); // Wait for and get the result of the future
    }
    result += last_result;

    return result;
}
