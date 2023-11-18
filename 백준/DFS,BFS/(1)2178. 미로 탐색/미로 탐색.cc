#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[104][104];
int visited[104][104];
string s;
queue<pair<int, int>> q;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void bfs(int y, int x){
	q.push({y, x});
	visited[y][x] = 1;
	
	while(q.size()){
		int a, b; 
		tie(a, b) = q.front(); q.pop();

		for(int i = 0 ; i < 4 ; i++){
			int ny = a + dy[i];
			int nx = b + dx[i];
			
			if( ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if(arr[ny][nx] && !visited[ny][nx]){
				q.push({ny, nx});
				visited[ny][nx] = visited[a][b] + 1;
			}	
		}
	}
}

int main(){
	cin >> N >> M;
	for(int i = 0 ; i < N ; i++){
		cin >> s;
		for(int j = 0 ; j < M ; j++){
			arr[i][j] = s[j] - '0';
		}
	}
	bfs(0, 0);
	cout << visited[N-1][M-1];
	
	return 0;
}

