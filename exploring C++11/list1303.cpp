#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> data;
    istream_iterator<int> input_it(cin);
    istream_iterator<int> end_it;
    while (input_it != end_it && (*input_it) != EOF) {
        try {
            data.push_back(*input_it++);
        } catch (const invalid_argument& e) {
            cerr << "An input error occurred: " << e.what() << endl;
            break;
        } catch (const out_of_range& e) {
            cerr << "An input error occurred: " << e.what() << endl;
            break;
        }
    }

    sort(data.begin(), data.end());
    vector<int>::iterator it = unique(data.begin(), data.end());
    data.erase(it, data.end());

    cout << "{";
    for (size_t i = 0; i < data.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << data[i];
    }
    cout << "}" << endl;

    return 0;
}
