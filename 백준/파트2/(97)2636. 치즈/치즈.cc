#include <bits/stdc++.h>
using namespace std;

int n, m;
int visited[104][104], arr[104][104];
int num, cnt, cnt2;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void bfs(int y, int x){
	queue<pair<int, int>> q;
	q.push({y, x});
	visited[y][x] = num;
	cnt++;
	
	while(q.size()){
		int a, b;
		tie(a, b) = q.front();
		q.pop();
		
		for(int i = 0 ; i < 4 ; i++){
			int ny = a + dy[i];
			int nx = b + dx[i];
			
			if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if(visited[ny][nx] == num) continue;
			
			if(arr[ny][nx] == 1 && visited[ny][nx] == 0){
				visited[ny][nx] = num;
				cnt++;
				arr[ny][nx] = 0;
				cnt2++;
			}
			else if(arr[ny][nx] == 0 && visited[ny][nx] == (num-1)){
				q.push({ny,nx});
				visited[ny][nx] = num;
				cnt++;
			}
			else if(arr[ny][nx] == 0 && visited[ny][nx] == 0){
				q.push({ny,nx});
				visited[ny][nx] = num;
				cnt++;
			}
		}
	} 
}
 

int main(){
	cin >> n >> m;
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> arr[i][j];
		}
	}
	
	while(true){
		bool flag = 0;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				if(arr[i][j] == 1){
					flag = 1;
				}
			}
		}
		if(flag == 0){
			break;
		}
		
		cnt = 0;
		cnt2 = 0;
		num++;
		
		bfs(0,0);
	}
	cout << num << "\n";
	cout << cnt2 << "\n";
	
	return 0;
}
