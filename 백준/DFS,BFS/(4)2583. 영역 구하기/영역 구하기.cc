#include <bits/stdc++.h>
using namespace std;

int M, N, K, num, cnt;
int arr[104][104], dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
vector<int> v;

void dfs(int y, int x){
	arr[y][x] = 1;
	num++;
	for(int i = 0 ; i < 4 ; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
		if(arr[ny][nx] == 0){
			dfs(ny, nx);
		}
	}
}

int main(){
	cin >> M >> N >> K;
	
	while(K--){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		for(int i = y1 ; i < y2 ; i++){
			for(int j = x1 ; j < x2 ; j++){
				arr[i][j] = 1;
			}
		}
	}
	
	for(int i = 0 ; i < M ; i++){
		for(int j = 0 ; j < N ; j++){
			if(arr[i][j] == 0){
				num = 0;
				dfs(i, j);
				v.push_back(num);
				cnt++;
			}
		}
	}
	sort(v.begin(), v.end(), less<int>());
	cout << cnt << "\n";
	for(int i = 0 ; i < v.size() ; i++){
		cout << v[i] << " ";
	}
	
	return 0;
}
