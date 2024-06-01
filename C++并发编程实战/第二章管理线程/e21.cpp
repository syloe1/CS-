struct func
{
    int& i;
    func(int& i) : i(i)() {}
};

void operator()()
{
    for(unsigned j = 0; j < 100000; ++j)
    {
        // 对悬空引用可能的访问
        do_something(i);
    }
}

void oops()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    // 不等待线程完成
    std::thread my_thread(my_func);
    // 新的线程可能仍在运行
    my_thread.detach(); //显示地决定不等待它 
}
