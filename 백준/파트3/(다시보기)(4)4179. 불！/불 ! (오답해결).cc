#include<bits/stdc++.h>
using namespace std;

char arr[1004][1004];
int visited[1004][1004], fvisited[1004][1004], temp[1004][1004];
int dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1}, r, c;
vector<pair<int, int>> v1, v2;
pair<int,int> p1;

void bfs1(int y, int x){
	queue<pair<int,int>> q;
	q.push({y, x});
	visited[y][x] = 1;
	while(q.size()){
		tie(y, x) = q.front();
		q.pop();
		
		for(int i = 0 ; i < 4 ; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx]) continue;
			if(arr[ny][nx] == '#' || arr[ny][nx] == 'F') continue;
			q.push({ny, nx});
			visited[ny][nx] = visited[y][x] + 1;
		}
	}
}

void bfs2(int y, int x){
	queue<pair<int,int>> q;
	q.push({y, x});
	temp[y][x] = 1;
	
	while(q.size()){
		tie(y, x) = q.front();
		q.pop();
		
		for(int i = 0 ; i < 4 ; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= r || nx >= c || temp[ny][nx] != 987654321) continue;   //emp[ny][nx] != 987654321 추가하기기
			if(arr[ny][nx] == '#') continue;
			if(arr[ny][nx] == '.' || arr[ny][nx] == 'J' || arr[ny][nx] == 'F'){      // arr[ny][nx] == 'F' 추가해주기
				q.push({ny, nx});
				temp[ny][nx] = temp[y][x] + 1;
			}
		}
	}
	
	for(i기
		bfs2(it.first, it.second);
	}
	bfs1(p1.first, p1.second);
	
	
	for(int i = 0 ; i < r ; i++){
		for(int j = 0 ; j < c ; j++){
			if(i == 0 && arr[i][j] != '#') v2.push_back({i, j});
			else if(i == r-1 && arr[i][j] != '#' ) v2.push_back({i, j});
			else if(j == 0 && i != 0 && i != r-1 && arr[i][j] != '#') v2.push_back({i, j});
			else if(j == c-1 && i != 0 && i != r-1 && arr[i][j] != '#') v2.push_back({i, j});
		}
	}


	int ret = 987654321;
	bool flag = 0;
	for(auto it : v2){
		if(arr[it.first][it.second] == 'F') continue;
		if(visited[it.first][it.second] < 1) continue;
		if(visited[it.first][it.second] < fvisited[it.first][it.second]){
			ret = min(ret, visited[it.first][it.second]);
			flag = 1;
		}
	}
	
	if(flag) cout << ret << "\n";
	else cout << "IMPOSSIBLE" << "\n";
	
	
	
	return 0;
}
