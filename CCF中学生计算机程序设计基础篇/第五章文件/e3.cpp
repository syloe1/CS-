#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ofstream fout;
int main() {
    string fname, f1, f2;
    int A, B;

    cout << "请输入文件名：";
    cin >> fname;
    // 键盘输入文件名

    cout << "请输入A和B的值:";
    cin >> A >> B;
    // 键盘输入整数A和B

    // 打开输出文件(.in)，输出A和B
    fout.open((fname + ".in").c_str());
    if (!fout) {
        cerr << "无法打开文件：" + fname + ".in" << endl;
        return 1;
    }
    fout << A << " " << B << endl;

    fout.close();

    // 打开输出文件(.out)，输出A+B
    fout.open((fname + ".out").c_str());
    if (!fout) {
        cerr << "无法打开文件：" + fname + ".out" << endl;
        return 1;
    }
    fout << A + B << endl;

    fout.close();

    return 0;
}
