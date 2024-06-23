//给定一个只包含小写字母的字符串， 请你找到第一个仅出现
//一次的字符。如果没有， 输出no
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

    // 第一次遍历，统计每个字符出现的次数
    for (char c : s) {
        charCount[c]++;
    }

    // 第二次遍历，找到第一个出现一次的字符
    for (int i = 0; i < s.size(); i++) {
        if (charCount[s[i]] == 1) {
            cout << s[i];
            return 0;
        }
    }

    cout << "no" << endl;
    return 0;
}
