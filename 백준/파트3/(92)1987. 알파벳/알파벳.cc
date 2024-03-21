#include<bits/stdc++.h>
using namespace std;

int dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1}, r, c, ret = -1, visited[24][24], alpha[30], cnt;
char arr[24][24];
string s;
bool flag;

void dfs(int y, int x){
	flag = 0;
	visited[y][x] = 1;
	alpha[arr[y][x] - 'A'] = 1;
	cnt++;
	
	for(int i = 0 ; i < 4 ; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		if(visited[ny][nx])continue;
		if(alpha[arr[ny][nx] - 'A']) continue;
		flag = 1;
		dfs(ny,nx);
		visited[ny][nx] = 0;
		alpha[arr[ny][nx] - 'A'] = 0;
		cnt--;
	}
	
	if(flag != 1){
		ret = max(ret, cnt);
	}
	
}

int main(){
	
	cin >> r >> c;
	
	for(int i = 0 ; i < r ; i++){
		cin >> s;
		for(int j = 0 ; j < c ; j++){
			arr[i][j] = s[j];
		}
	}
	
	dfs(0, 0);
	
	cout << ret << "\n";
	
	return 0;
}
