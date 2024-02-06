#include <bits/stdc++.h>
using namespace std;

vector<int> v[10004];
int dp[10004], visited[10004];
int n, m, cnt, mx, temp1, temp2;

void dfs(int here){
	visited[here] = 1;
	cnt++;
	
	for(int there : v[here]){
		if(visited[there]) continue; 
		dfs(there);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i=0 ; i < m ; i++){
		cin >> temp1 >> temp2;
		v[temp2].push_back(temp1);
	}
	
	for(int i=1 ; i <= n ; i++){
		dfs(i);
		dp[i] = cnt; 
		mx = max(mx, dp[i]);
		memset(visited, 0, sizeof(visited));
		cnt = 0;
	}
	for(int i=1 ; i <= n ; i++){
		if(mx == dp[i]) cout << i << " ";
	}
	
	return 0;
}
