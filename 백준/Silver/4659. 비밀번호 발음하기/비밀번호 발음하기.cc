#include <bits/stdc++.h>
using namespace std;

string s;
vector<char> v = {'a', 'e', 'i', 'o', 'u'};

int main() {
    while (cin >> s) {
        if (s == "end") break;

        bool is_include_v = false;
        bool flag = true;

        for (int i = 0; i < s.size(); i++) {
            auto a = find(v.begin(), v.end(), s[i]);

            // Check for consecutive vowels or consonants
            if (i + 2 < s.size()) {
                auto b = find(v.begin(), v.end(), s[i + 1]);
                auto c = find(v.begin(), v.end(), s[i + 2]);
                if (a != v.end() && b != v.end() && c != v.end()) {
                    flag = false;
                } else if (a == v.end() && b == v.end() && c == v.end()) {
                    flag = false;
                }
            }

            // Check for consecutive identical characters
            if (i + 1 < s.size() && s[i] == s[i + 1]) {
                if (s[i] != 'e' && s[i] != 'o') {
                    flag = false;
                }
            }

            if (a != v.end()) {
                is_include_v = true;
            }
        }

        if (!is_include_v || !flag) {
            cout << "<" << s << ">" << " is not acceptable." << "\n";
        } else {
            cout << "<" << s << ">" << " is acceptable." << "\n";
        }
    }

    return 0;
}