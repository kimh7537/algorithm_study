#include <bits/stdc++.h>
using namespace std;

vector<int> v[104];
bool visited[104];
int cnt;

void dfs(int start){
	visited[start] = true;
	
	for(int i : v[start]){
		if(!visited[i]){
			cnt++;
			dfs(i);
		}
	}
}


int main(){
	int N, E;
	cin >> N >> E;
	
	for(int i = 0 ; i < E ; i++){
		int a, b;
		cin >> a >> b;
		
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	dfs(1);
	
	cout << cnt << "\n";
	
	return 0;
}