#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> a;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m; //회원수, 최소 능력치

    int input, count = 0; //입력, 짝 개수

    for (int i = 0; i < n; i++){
        cin >> input;
        a.push_back(input);
    }

    sort(a.begin(), a.end());

    int st = 0, ed = a.size() - 1;

    while (st < ed)
    {
        int sum = a[st] + a[ed]; //m값과 비교

        if (sum < m){ //능력치 미달
            st++;
        } else {
            st++;
            ed--;
            count++;
        }
    }
    
    cout << count;
}