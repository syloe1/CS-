/*
ͳ���ַ���Johe����������ַ���Ϸ�������������ģ�������
���ַ��������е���ĸ���Ǵ�д�ģ�Johe���ӡһ����״ͼ��ʾÿ����д
��ĸ��Ƶ�ʡ����ܰ�������
�����ʽ�������ļ�����4�У�ÿ��Ϊһ���ַ���������100���ַ��� 
�����ʽ���������ĸ�ʽ�����ϸ�һ�¡�
����������
THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.
 THIS IS AN EXAMPLE TO TEST FOR YOUR
  HISTOGRAM PROGRAM.
  HELLO!
���������
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
    // ����һ���ַ��������洢ÿ����ĸ��Ƶ��
    int frequency[26] = {0};
    string line;
    const int lines = 4; // �ܹ���Ҫ��ȡ������

    // ��ȡ�����ַ���
    for (int i = 0; i < lines; ++i) {
        cin >> line;
        // �����ַ�����ͳ��ÿ����ĸ��Ƶ��
        for (char ch : line) {
            if (isupper(ch)) {
                frequency[ch - 'A']++;
            }
        }
    }

    // ��ӡ��״ͼ
    for (int i = 0; i < 26; ++i) {
        // ��ӡ�ո��Զ�����ĸ
        for (int j = 0; j < (26 - i - 1); ++j) {
            cout << "    ";
        }
        // ��ӡ�Ǻţ���ʾƵ��
        for (int j = 0; j < frequency[i]; ++j) {
            cout << "*";
        }
        cout << " " << char('A' + i) << endl; // ��ӡ��ĸ
    }

    return 0;
}
