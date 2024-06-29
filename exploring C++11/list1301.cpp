#include <iostream>
#include <vector>
#include <iterator> // 包含用于std::ostream_iterator的头文件

using namespace std;

int main() {
    vector<int> positive_data, negative_data;
    for (int x = 0; cin >> x; ) {
        if (x < 0) {
            negative_data.push_back(x); // 存储负数
        } else {
            positive_data.push_back(x); // 存储正数，修正了push_back的调用
        }
    }
    cout << "positive_data: \n";
    copy(positive_data.begin(), positive_data.end(), ostream_iterator<int>(cout, "\n")); // 使用正确的向量名
    cout << "negative_data: \n";
    copy(negative_data.begin(), negative_data.end(), ostream_iterator<int>(cout, "\n")); // 使用正确的向量名
    return 0;
}

