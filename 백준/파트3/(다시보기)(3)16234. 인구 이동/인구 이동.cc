#include <bits/stdc++.h>
using namespace std;

int n, l, r;
int cnt, sum, temp, result, chk;
int arr[54][54], visited[54][54], ret[54][54];
int dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};

void bfs(int y, int x){
	queue<pair<int, int>> q;
	q.push({y, x});
	cnt++;
	sum += arr[y][x];
	visited[y][x] = chk;
	
	while(q.size()){
		tie(y, x) = q.front();
		q.pop();
		
		for(int i=0 ; i < 4 ; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if(visited[ny][nx]) continue;
			if(l <= abs(arr[ny][nx] - arr[y][x]) && abs(arr[ny][nx] - arr[y][x]) <= r){
				q.push({ny, nx});
				visited[ny][nx] = chk;
				cnt++;
				sum += arr[ny][nx];
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> l >> r;
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			cin >> arr[i][j];
		}
	}

	while(1){
		bool flag = 0;
		chk = 0;
		memset(visited, 0, sizeof(visited));
		for(int i=0; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				if(visited[i][j] == 0){
					cnt = 0;
					sum = 0;
					chk++;
					bfs(i, j);
					if(cnt > 1){
						temp = sum / cnt;
						flag = 1;
						
						for(int i1=0 ; i1<n ; i1++){
							for(int j1=0; j1<n ; j1++){
								if(visited[i1][j1] == chk){
									arr[i1][j1] = temp;
								}
								// else if(visited[i1][j1] == 0){  //없어도 됨(ret말고 arr에 바로 해도 정답)
								// 	ret[i1][j1] = arr[i1][j1];
								// }
							}
						}
					}
					else if(cnt == 1){ //없어도 됨, 이유는 인구 이동(3)에 적어둠
						visited[i][j] = 0;
					}
				}
			}
		}
		
		if(flag == 0){
			break;
		}
		else{
			result++;
			// memcpy(arr, ret, sizeof(ret));  //없어도 됨
		}
	}
	
	cout << result << "\n";
	
	return 0;
}
