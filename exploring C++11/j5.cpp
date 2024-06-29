//实现一个函数， 把字符串中的每个
#include <iostream>
#include <string>
#include <algorithm>

// 替换字符串中所有的空格为 "%20"
void replaceSpacesWithPercentTwenty(std::string& str) {
    std::string result;
    result.reserve(str.size() * 3); // 预分配足够的空间，防止多次重新分配
    for (char ch : str) {
        if (ch == ' ') {
            result += "%20"; // 空格替换为 "%20"
        } else {
            result += ch; // 非空格字符直接添加到结果中
        }
    }
    str = result; // 用新构建的字符串替换原字符串
}

int main() {
    std::string myString = "We are happy";
    replaceSpacesWithPercentTwenty(myString);

    std::cout << "Original string: " << myString << std::endl;
    return 0;
}
