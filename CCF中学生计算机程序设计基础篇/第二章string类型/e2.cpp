//����һ��ֻ����Сд��ĸ���ַ����� �����ҵ���һ��������
//һ�ε��ַ������û�У� ���no
#include <iostream> 
#include <string> 
using namespace std;
int main() {
	string s; cin>>s;
	for (int i = 0; i < s.size(); i++) {
		int c = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[i] == s[j]) c++;
		}
		if (c == 1) {
			cout<<s[i]; return 0;
		}
	}
	cout<<"no"<<endl;
	return 0;
}
//O(N)
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string s; cin >> s;
    unordered_map<char, int> charCount;

    // ��һ�α�����ͳ��ÿ���ַ����ֵĴ���
    for (char c : s) {
        charCount[c]++;
    }

    // �ڶ��α������ҵ���һ������һ�ε��ַ�
    for (int i = 0; i < s.size(); i++) {
        if (charCount[s[i]] == 1) {
            cout << s[i];
            return 0;
        }
    }

    cout << "no" << endl;
    return 0;
}
