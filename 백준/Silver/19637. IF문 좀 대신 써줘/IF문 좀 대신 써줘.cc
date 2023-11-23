#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;
vector<string> str;

int main() {
    ios::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int last = -1;
    for(int i = 0; i < n; i++){
        string s;
        int num;
        cin >> s >> num;
        if(num == last){
            continue;
        }
        last = num;
        v.push_back(num);
        str.push_back(s);
    }
    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        cout << str[lower_bound(v.begin(),v.end(), num) - v.begin()] << "\n";
    }
    return 0;
}