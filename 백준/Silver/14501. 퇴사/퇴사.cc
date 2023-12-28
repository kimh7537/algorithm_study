#include <bits/stdc++.h>
using namespace std;

int n;

int main(){

	cin >> n;
	
	vector<pair<int, int>> arr(n);
	vector<int> dp(n + 1, 0);
	 
	for (int i = 0; i < n; i++){
		cin >> arr[i].first >> arr[i].second;
	}

	for (int i = 0; i < n; i++){
		for (int j = i + arr[i].first; j <= n; j++){
			dp[j] = max(dp[j], arr[i].second + dp[i]);
		}
	}

	cout << dp[n] << "\n";

	return 0;
}