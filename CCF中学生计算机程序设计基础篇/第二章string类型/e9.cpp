//单词替换
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string s, s1, s2;
    getline(cin, s); // 读取原始文本
    getline(cin, s1); // 读取要被替换的单词
    getline(cin, s2); // 读取替换后的单词

    // 确保替换操作在原始文本中进行
    for (int k = 0; (k = s.find(s1, k)) != string::npos; k += s1.size()) {
        s.replace(k, s1.size(), s2);
    }

    // 输出替换后的结果
    cout << s;

    return 0;
}
