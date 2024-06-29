#include <cstdio>
#include <fstream>
#include <iostream>

int main() {
    // 方法1: 使用双反斜杠
    std::ifstream in{"C:\\Users\\Administrator\\Desktop\\准备\\explorec++11\\1.txt"};
    
    // 方法2: 使用原始字符串字面量
    // std::ifstream in{R"(C:\Users\Administrator\Desktop\准备\explorec++11\1.txt)"};

    if (!in) {
        std::perror("Error opening file");
    } else {
        int x{};
        while (in >> x) {
            std::cout << x << '\n';
        }
        in.close();
    }
    return 0;
}
