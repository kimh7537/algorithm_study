#include<bits/stdc++.h>
using namespace std;

int n, res, temp;
vector<int> dist, cost;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i = 0 ; i < n - 1 ; i++){
		cin >> temp;
		dist.push_back(temp);
	}
	for(int i = 0 ; i < n ; i++){
		cin >> temp;
		cost.push_back(temp);
	}
	
	res = cost[0] * dist[0];
	for(int i = 1 ; i < n ; i++){
		if(cost[i-1] >= cost[i]){
			res += (cost[i] * dist[i]);
		}else if(cost[i-1] < cost[i]){
			res += (cost[i-1] * dist[i]);
		}
	}
	
	cout << res << "\n";
	
	return 0;
}