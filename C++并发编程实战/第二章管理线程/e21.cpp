struct func
{
    int& i;
    func(int& i) : i(i)() {}
};

void operator()()
{
    for(unsigned j = 0; j < 100000; ++j)
    {
        // ���������ÿ��ܵķ���
        do_something(i);
    }
}

void oops()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    // ���ȴ��߳����
    std::thread my_thread(my_func);
    // �µ��߳̿�����������
    my_thread.detach(); //��ʾ�ؾ������ȴ��� 
}
