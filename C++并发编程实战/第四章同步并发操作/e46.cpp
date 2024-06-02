//使用future获取异步任务的返回值
#include <future>
#include <iostream>
using namespace std; 

int find_the_answer_to_ultimate_question() {
    // 模拟一些耗时的计算
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 42;  // 返回终极问题的答案
}

void do_other_stuff() {
    // 模拟其他工作
    std::cout << "Doing other stuff..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Finished other stuff." << std::endl;
}

int main() {
    std::future<int> the_answer = std::async(find_the_answer_to_ultimate_question);
    do_other_stuff();
    std::cout << "The answer is " << the_answer.get() << std::endl;
    return 0;
}


