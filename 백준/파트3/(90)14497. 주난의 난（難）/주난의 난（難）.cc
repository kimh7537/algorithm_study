#include <bits/stdc++.h>
using namespace std;
#define y1 aaaa
int cnt, n, m, x1, y1, x2, y2;
int visited[304][304], arr[304][304], dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
bool flag;

void bfs(int y, int x){
	queue<pair<int, int>> q;
	q.push({y, x});
	visited[y][x] = 1;
	
	while(q.size()){
		tie(y, x) = q.front();
		q.pop();
		
		for(int i = 0 ; i < 4 ; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if(visited[ny][nx]) continue;
			if(ny == y2-1 && nx == x2 -1){
				flag = 1;
				return;
			}
			if(arr[ny][nx] == 1) {
				arr[ny][nx] = 0;
				visited[ny][nx] = 1;
			}else{
				visited[ny][nx] = 1;
				q.push({ny, nx});
			}
			
		}
	}
}

int main(){
	cin >> n >> m;
	cin >> y1 >> x1 >> y2 >> x2;
	
	string s;
	for(int i = 0 ; i < n ; i++){
		cin >> s;
		for(int j = 0 ; j < m ; j++){
			arr[i][j] = s[j] - '0';
		}
	}
	
	while(true){
		cnt++;
		memset(visited, 0 , sizeof(visited));
		bfs(y1-1, x1-1);
		
		if(flag == 1) break;
	}
	
	cout << cnt << "\n";
	
	return 0;
}
