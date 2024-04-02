#include <bits/stdc++.h>
using namespace std;

int n, visited[14][14], arr[14][14], ret = 987654321;

int check(int y, int x, int v){
	visited[y][x] = v;
	visited[y+1][x] = v;
	visited[y-1][x] = v;
	visited[y][x-1] = v;
	visited[y][x+1] = v;
	
	int t = 0;
	t += arr[y][x];
	t += arr[y+1][x];
	t += arr[y-1][x];
	t += arr[y][x+1];
	t += arr[y][x-1];
	return t;
}

void go(int here, int cnt, int sum){
	if(cnt == 3){
		ret = min(ret, sum);
		return;
	}
	
	for(int i = here ; i < n-1 ; i++){
		for(int j = 1 ; j < n-1 ; j++){
			if(visited[i][j] || visited[i-1][j] || visited[i+1][j] || visited[i][j+1] || visited[i][j-1]) continue;
			int temp = check(i, j, 1);
			go(i, cnt + 1, sum + temp);
			temp = check(i, j, 0);
		}
	}
} 

int main(){
	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> arr[i][j];
		}
	}

	go(1, 0, 0);
	cout << ret << "\n";
	return 0;
}
