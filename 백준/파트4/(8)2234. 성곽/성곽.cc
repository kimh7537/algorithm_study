#include <bits/stdc++.h>
using namespace std;

int arr[54][54], m, n, cnt, ret, result = -1, visited[54][54], ny, nx, result2 = -1;

void bfs(int y, int x){
	queue<pair<int, int>> q;
	q.push({y, x});
	visited[y][x] = 1;
	cnt++;
	
	while(q.size()){
		tie(y, x) = q.front();
		q.pop();
		
		for(int i = 0 ; i < 4 ; i++){
			if(!(arr[y][x] & (1 << i))){
				if(i == 3){
					ny = y+1;
					nx = x;
				}else if(i == 2){
					ny = y;
					nx = x+1;
				}else if(i == 1){
					ny = y-1;
					nx = x;
				}else if(i == 0){
					ny = y;
					nx = x-1;
				}
				if(ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
				if(visited[ny][nx]) continue;
				q.push({ny, nx});
				visited[ny][nx] = 1;
				cnt++;
			}
			
		}
	}
}

int main(){
	cin >> n >> m;
	
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> arr[i][j];
		}
	}
	
	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			cnt = 0;
			if(visited[i][j] == 0){
				bfs(i, j);
				ret++;
				result = max(result, cnt);
			}
		}
	}
	int flag = 0;
	memset(visited, 0 , sizeof(visited));

	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			flag = 0;
			cnt = 0;

			if(i == 0){
				flag += 2;
			}else if(i == m-1){
				flag += 8;
			}
			
			if(j == 0){
				flag += 1;
			}else if(j == n-1){
				flag += 4;
			}

			for(int k = 0 ; k < 4 ; k++){
				if(arr[i][j] & (1 << k) && !(flag & (1 << k))){
					arr[i][j] -= (1 << k);
					bfs(i, j);
					result2 = max(result2, cnt);
					cnt = 0;
					memset(visited, 0 , sizeof(visited));
					arr[i][j] += (1 << k);
				}
			}
		}
	}
	
	cout << ret << "\n";
	cout << result << "\n";
	cout << result2 << "\n";
	
	
	return 0;
}
