//ʹ��future��ȡ�첽����ķ���ֵ
#include <future>
#include <iostream>
using namespace std; 

int find_the_answer_to_ultimate_question() {
    // ģ��һЩ��ʱ�ļ���
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 42;  // �����ռ�����Ĵ�
}

void do_other_stuff() {
    // ģ����������
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


