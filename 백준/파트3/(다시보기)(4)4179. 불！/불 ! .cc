#include<bits/stdc++.h>
using namespace std;

char arr[1004][1004];
int visited[1004][1004], fvisited[1004][1004], temp[1004][1004];
int dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1}, r, c;
vector<pair<int, int>> v1, v2;
pair<int,int> p1;
queue<pair<int,int>> q1;

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

void bfs2(){
	
	int y, x;
	
	while(q1.size()){
		tie(y, x) = q1.front();
		q1.pop();
		
		for(int i = 0 ; i < 4 ; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= r || nx >= c || fvisited[ny][nx] != 987654321) continue;
			if(arr[ny][nx] == '#') continue;
			if(arr[ny][nx] == '.' || arr[ny][nx] == 'J'){
				q1.push({ny, nx});
				fvisited[ny][nx] = fvisited[y][x] + 1;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> r >> c;
	
	fill(&fvisited[0][0], &fvisited[0][0] + 1004 * 1004, 987654321);
	
	for(int i=0 ; i < r ; i++){
		for(int j=0 ; j < c ; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 'J') p1 = {i, j};
			else if(arr[i][j] == 'F') q1.push({i, j}), fvisited[i][j] = 1;
		}
	}
	
	bfs2();
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
