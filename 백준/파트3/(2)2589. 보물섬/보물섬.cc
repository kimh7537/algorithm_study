#include<bits/stdc++.h>
using namespace std;

int n, m, ret;
char arr[54][54];
int visited[54][54];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int y, int x){
	memset(visited, 0, sizeof(visited));
	queue<pair<int,int>> q;
	q.push({y, x});
	visited[y][x] = 1;
	
	while(q.size()){
		tie(y, x) = q.front();
		q.pop();

		for(int i=0 ; i<4 ; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny<0 || nx<0 || ny>=n || nx>=m ) continue;
			if(arr[ny][nx] != 'L') continue;
			if(visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ny, nx});
			ret = max(ret, visited[ny][nx]);
		}
	}
}

int main(){
    cin >> n >> m; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j]; 
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 'L'){
            	bfs(i, j);
			}
        }
    }
    cout << ret - 1 << "\n";
    
    return 0;
}
