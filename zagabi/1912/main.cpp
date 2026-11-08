#include<bits/stdc++.h>

using namespace std;

int num, n;
vector<int> v;
int dp[100004];

int main(){

	cin >> num;
	
	for(int i = 0 ; i < num ; i++){
		cin >> n;
		v.push_back(n);
	}
	
	dp[0] = v[0];
	for(int i = 1 ; i < num ; i++){
		dp[i] = max(dp[i-1] + v[i], v[i]);
	}
	
	int mx = *max_element(dp, dp+num);
	
	cout << mx << "\n";
	
	return 0;
}