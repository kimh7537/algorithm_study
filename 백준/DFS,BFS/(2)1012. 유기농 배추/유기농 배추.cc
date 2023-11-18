#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int arr[54][54] = {0, };
int visited[54][54] = {0, };
int T, M, N, K;
vector<int> v;

void dfs(int y, int x){
	visited[y][x] = 1;
	
	for(int i = 0 ; i < 4 ; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
		if(arr[ny][nx] == 0) continue;
		if(visited[ny][nx]) continue;
		dfs(ny, nx);
	}
}

int main(){
	int num1, num2;
	
	cin >> T;
	for(int i = 0 ; i < T ; i++){
		int cnt = 0;
		
		cin >> M >> N >> K;
		for(int i = 0 ; i < K ; i++){
			cin >> num1 >> num2;
			arr[num2][num1] = 1; 
		}
		
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < M ; j++){
				
				if((arr[i][j] == 1) && (visited[i][j] == 0)){
					dfs(i, j);
					cnt++;
				}
			}
		}
		v.push_back(cnt);
		memset(arr, 0, sizeof(arr));
		memset(visited, 0 , sizeof(arr));
	}
	
	for(int i = 0 ; i < v.size() ; i++){
		cout << v[i] << "\n";
	}

	return 0;
}
