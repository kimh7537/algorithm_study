#include <bits/stdc++.h>
using namespace std;

int arr[104][104];
int visited[104][104];
int N;
vector<int> v;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int y, int x){
	visited[y][x] = 1;
	
	for(int i = 0 ; i < 4 ; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny < 0 | nx < 0 | ny >= N | nx >= N) continue;
		if(visited[ny][nx]) continue;
		dfs(ny, nx);
	}
	
}


int main(){
	
//	int max_num;
	cin >> N;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cin >> arr[i][j];
//			if(arr[i][j] > max_num) max_num = arr[i][j];
		}
	}
	
	for(int k = 0 ; k <= 100 ; k++){
		int count = 0;
		
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < N ; j++){
				if(arr[i][j] <= k) visited[i][j] = 1;
			}
		}
		
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < N ; j++){
				if(visited[i][j] == 0) {
					dfs(i, j);
					count++;
				}
			}
		}
	
		v.push_back(count);
		memset(visited, 0, sizeof(visited));
		
	}
	
	sort(v.begin(), v.end(), greater<int>());
	
	cout << v[0];
	
	
	return 0;
}
