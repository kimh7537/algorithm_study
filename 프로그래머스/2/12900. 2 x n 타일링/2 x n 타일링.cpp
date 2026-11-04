#include <bits/stdc++.h>

using namespace std;

int dp[60004];

int solution(int n) {
    int answer = 0;
    
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i = 3 ; i <=n ; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
    }
    
    cout << dp[4] << "\n";
    cout << dp[5] << "\n";
    
    return dp[n];
}