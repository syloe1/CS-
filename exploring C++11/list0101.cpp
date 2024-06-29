#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

void read(istream& in, vector<string>& text) {
    string line;
    while (getline(in, line)) 
        text.push_back(line);
}

int main(int argc, char *argv[]) {
    vector<string> text;
    if (argc < 2) 
        read(cin, text);
    else {
        ifstream in(argv[1]);
        if (not in) {
            perror(argv[1]);
            return EXIT_FAILURE;
        }
        read(in, text);
    }

    sort(text.begin(), text.end());
    copy(text.begin(), text.end(), 
         ostream_iterator<string>(cout, "\n"));
    return 0;
}

