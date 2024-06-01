//生成一批线程并等待它们生成
 void do_work(unsigned id);

void f() {
    std::vector<std::thread> threads;
    for (unsigned i = 0; i < 20; ++i) {
        // 生成线程
        threads.push_back(std::thread(do_work, i));
    }
    std::for_each(threads.begin(), threads.end(),
                   std::mem_fn(&std::thread::join));
    // 调用join()
}
