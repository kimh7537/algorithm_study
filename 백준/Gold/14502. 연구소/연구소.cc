#include <bits/stdc++.h>
using namespace std;

int n, m, ret, a, b;
int arr[12][12], visited[12][12], temp[12][12];
int dy[4] = {1, -1, 0 , 0};
int dx[4] = {0, 0, 1, -1};
vector<pair<int, int>> v1, v2;

void bfs(int y, int x){
	queue<pair<int,int>> q;
	q.push({y,x});
	
	int r1, r2;
	while(q.size()){
		tie(r1, r2) = q.front();
		q.pop();
		
		for(int i = 0 ; i < 4 ; i++){
			int ny = r1 + dy[i];
			int nx = r2 + dx[i];
			if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if(visited[ny][nx] == 0){
				q.push({ny,nx});
				visited[ny][nx] = 1;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 2) v1.push_back({i, j});
			if(arr[i][j] == 0) v2.push_back({i, j});
		}
	}
	
	for(int i=0 ; i < v2.size() ; i++){
		for(int j=i+1 ; j < v2.size() ; j++){
			for(int k=j+1 ; k < v2.size() ; k++){
				memcpy(visited, arr, sizeof(arr));
				int cnt = 0;
				visited[v2[i].first][v2[i].second] = 1;
				visited[v2[j].first][v2[j].second] = 1;
				visited[v2[k].first][v2[k].second] = 1;
				
				for(int q = 0 ; q < v1.size() ; q++){
					tie(a,b) = v1[q];
					bfs(a,b);
				}
				
				for(int z = 0 ; z < n ; z++){
					for(int o = 0 ; o < m ; o++){
						if(visited[z][o] == 0){
							cnt++;
						}
					}
				}
				ret = max(cnt, ret);
				
			}
		}
	}
	
	cout << ret << "\n";
	
	return 0;
}