#include <bits/stdc++.h>
using namespace std;
 
int arr[504][504];
int dp[504][504] = {0};
int n, mx;
 
int main() {
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> arr[i][j];
        }
    }
    
    dp[1][1] = arr[1][1];
    
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
        }
    }
    
    for(int i = 1; i <= n; i++){
        mx = max(dp[n][i], mx);
    }
    
    cout << mx << '\n';
    
    return 0;
}