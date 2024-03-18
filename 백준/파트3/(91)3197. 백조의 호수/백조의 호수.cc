#include <bits/stdc++.h>
using namespace std;

int cnt, n, m, visited[1504][1504], svisited[1504][1504], dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1}, sy, sx;
char arr[1504][1504];
queue<pair<int, int>> wq;
queue<pair<int, int>> sq;
string s;
bool flag;

void bfs(){
	
	queue<pair<int,int>> temp;
	int y, x;
	while(wq.size()){
		tie(y, x) = wq.front();
		wq.pop();
		
		for(int i = 0 ; i < 4 ; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if(visited[ny][nx]) continue;
			if(arr[ny][nx] == 'X'){
				arr[ny][nx] = '.';
				temp.push({ny, nx});
			}else{
				wq.push({ny, nx});
			}
			visited[ny][nx] = 1;
		}
	}
	wq = temp;  //중요
}

void sbfs(){

	queue<pair<int,int>> temp;
	int y, x;
	while(sq.size()){
		tie(y, x) = sq.front();
		sq.pop();
		
		for(int i = 0 ; i < 4 ; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if(svisited[ny][nx]) continue;
			if(arr[ny][nx] == 'L'){
				flag = 1;
				return;
			}
			if(arr[ny][nx] == 'X') {
				temp.push({ny, nx});
			}else{
				sq.push({ny, nx});
			}
			svisited[ny][nx] = 1;	
		}
	}
	sq = temp;   //중요
}


int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
		cin >> s;
		for(int j = 0 ; j < m ; j++){
			arr[i][j] = s[j];
			if(arr[i][j] == 'L'){
				sy = i;
				sx = j;
			}
			if(arr[i][j] == 'L' || arr[i][j] == '.'){
				wq.push({i, j});
				visited[i][j] = 1;
			}
		}
	}
	
	sq.push({sy, sx});
	svisited[sy][sx] = 1;
	while(true){
		
		cnt++;
		bfs();
		sbfs();
		if(flag){
			break;
		}
	}
	
	cout << cnt << "\n";
	
	return 0;
}
