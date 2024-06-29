#include <iostream>
#include <vector>
#include <iterator> // ��������std::ostream_iterator��ͷ�ļ�

using namespace std;

int main() {
    vector<int> positive_data, negative_data;
    for (int x = 0; cin >> x; ) {
        if (x < 0) {
            negative_data.push_back(x); // �洢����
        } else {
            positive_data.push_back(x); // �洢������������push_back�ĵ���
        }
    }
    cout << "positive_data: \n";
    copy(positive_data.begin(), positive_data.end(), ostream_iterator<int>(cout, "\n")); // ʹ����ȷ��������
    cout << "negative_data: \n";
    copy(negative_data.begin(), negative_data.end(), ostream_iterator<int>(cout, "\n")); // ʹ����ȷ��������
    return 0;
}

