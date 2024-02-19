#include <bits/stdc++.h>
using namespace std;
int visited[54][54], a[54][54], n, l, r, sum, cnt; 
const int dy[]={-1,0,1,0};
const int dx[] ={0,1,0,-1}; 
vector<pair<int,int>>v;

void bfs(int y, int x, vector<pair<int, int>> &v){
	queue<pair<int, int>> q;
	q.push({y, x});

	while(q.size()){
		tie(y, x) = q.front();
		q.pop();
		
		for(int i=0 ; i < 4 ; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if(visited[ny][nx]) continue;
			if(l <= abs(a[ny][nx] - a[y][x]) && abs(a[ny][nx] - a[y][x]) <= r){
				q.push({ny, nx});
				visited[ny][nx] = 1;
				v.push_back({ny, nx});
				sum += a[ny][nx];
			}
		}
	}
}

int main(){ 
    cin>>n>>l>>r;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    while(true){
        bool flag =0;
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j]){
                    v.clear();
                    visited[i][j] = 1;
                    v.push_back({i,j});
                    sum = a[i][j];
                    bfs(i,j,v);
                    if(v.size() == 1) continue;  
                    for(pair<int,int> b : v){ 
                        a[b.first][b.second] = sum / v.size();
                        flag = 1;
                    }
                } 
            }
        }
        if(!flag) break;  
        cnt++;
    } 
    cout<< cnt << "\n";
    return 0;
}
