#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ofstream fout;
int main() {
    string fname, f1, f2;
    int A, B;

    cout << "�������ļ�����";
    cin >> fname;
    // ���������ļ���

    cout << "������A��B��ֵ:";
    cin >> A >> B;
    // ������������A��B

    // ������ļ�(.in)�����A��B
    fout.open((fname + ".in").c_str());
    if (!fout) {
        cerr << "�޷����ļ���" + fname + ".in" << endl;
        return 1;
    }
    fout << A << " " << B << endl;

    fout.close();

    // ������ļ�(.out)�����A+B
    fout.open((fname + ".out").c_str());
    if (!fout) {
        cerr << "�޷����ļ���" + fname + ".out" << endl;
        return 1;
    }
    fout << A + B << endl;

    fout.close();

    return 0;
}
