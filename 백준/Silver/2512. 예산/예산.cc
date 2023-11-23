#include <bits/stdc++.h>
using namespace std;

int n, budget;
vector<int> v;

int main() {
    cin >> n;
    vector<int> v(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    cin >> budget;

    sort(v.begin(), v.end());

    int l = 0;
    int r = v[n - 1];
    int ret = 0;
    
    while (l <= r) {
        int sum = 0;
        int m = (l + r) / 2;
        for (int i = 0; i < n; ++i){
            if (v[i] < m) sum += v[i];
            else {
                sum += m * (n - i);
                break;
            }
        }
        if (sum > budget) {
            r = m - 1;
        }
        else {
            l = m + 1;
            ret = max(m, ret);
        }
    }
    cout << ret;
}
