#include<bits/stdc++.h>
using namespace std;

int r, c, k, visited[10][10], cnt, dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0 , 0};
char arr[10][10];

void dfs(int y, int x){
	if(y == 0 && x == c-1 && visited[y][x] == k){
		cnt++;
		return;
	}
	if(visited[y][x] > k) return;
	
	for(int i = 0 ; i < 4 ; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		if(visited[ny][nx]) continue;
		if(arr[ny][nx] == 'T') continue;
		visited[ny][nx] = visited[y][x] + 1;
		dfs(ny, nx);
		visited[ny][nx] = 0;
	}
}

int main(){
	cin >> r >> c >> k;
	
	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++){
			cin >> arr[i][j];
		}
	}
	
	visited[r-1][0] = 1;
	dfs(r-1, 0);
	
	cout << cnt << "\n";
	
	
	return 0;
}
