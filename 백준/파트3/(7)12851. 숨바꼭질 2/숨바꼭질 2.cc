#include<bits/stdc++.h>
using namespace std;

int n, k, ret, temp = 987654321;
int visited[100004];


void solve(int idx, int sum){
	queue<pair<int,int>> q;
	q.push({idx, sum});
//	visited[sum] 
	
	while(q.size()){
		tie(idx, sum) = q.front();
		q.pop();
		visited[sum] = 1;

		if(sum == k && ret == 0){
			ret++;
			temp = idx;
		}else if(sum == k && ret > 0 && idx == temp){
			ret++;
		}
		if(idx > temp) continue;
		
		if(0 <= sum-1 && !visited[sum-1]){
			q.push({idx+1, sum-1});
		}
		if(sum+1 <= k+1 && !visited[sum + 1]){
			q.push({idx+1, sum+1});
		}
		if(sum*2 <= k+1 && !visited[sum * 2]){
			q.push({idx+1, sum*2});
		}
	}
	
}

int main(){
	cin >> n >> k;
	
	solve(0, n);
	
	cout << temp << "\n";
	cout << ret << "\n";
	
	return 0;
}
