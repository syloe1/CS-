/*
统计字符。Johe最近玩起了字符游戏，规则是这样的：读入四
行字符串，其中的字母都是大写的，Johe想打印一个柱状图显示每个大写
字母的频率。你能帮助他吗？
输入格式：输入文件共有4行，每行为一串字符，不超过100个字符。 
输出格式：与样例的格式保持严格一致。
输入样例：
THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.
 THIS IS AN EXAMPLE TO TEST FOR YOUR
  HISTOGRAM PROGRAM.
  HELLO!
输出样例：
                            *
                             *
         *                   *
         *                   *     *   *
         *                   *     *   *
 *       *     *             *     *   *
 *       *     * *     * *   *     * * *
 *       *   * * *     * *   * *   * * * *
 *     * * * * * *     * * * * *   * * * *     * *
 * * * * * * * * * * * * * * * * * * * * * * * * * *
 A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
*/
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main() {
    // 定义一个字符数组来存储每个字母的频率
    int frequency[26] = {0};
    string line;
    const int lines = 4; // 总共需要读取的行数

    // 读取四行字符串
    for (int i = 0; i < lines; ++i) {
        cin >> line;
        // 遍历字符串，统计每个字母的频率
        for (char ch : line) {
            if (isupper(ch)) {
                frequency[ch - 'A']++;
            }
        }
    }

    // 打印柱状图
    for (int i = 0; i < 26; ++i) {
        // 打印空格，以对齐字母
        for (int j = 0; j < (26 - i - 1); ++j) {
            cout << "    ";
        }
        // 打印星号，表示频率
        for (int j = 0; j < frequency[i]; ++j) {
            cout << "*";
        }
        cout << " " << char('A' + i) << endl; // 打印字母
    }

    return 0;
}
