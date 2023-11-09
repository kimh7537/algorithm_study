#include<bits/stdc++.h> 
using namespace std;

#define y1 aaaa 
int a[104][104], M, N, K, x1, x2, y1, y2, visited[104][104];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
vector<int> ret; 

int dfs(int y, int x){
    visited[y][x] = 1; 
    int ret = 1; 
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i]; 
        int nx = x + dx[i]; 
        if(ny < 0 || ny >= M || nx < 0 || nx >= N || visited[ny][nx] == 1) continue; 
		if(a[ny][nx] == 1) continue;
        ret += dfs(ny, nx);
    } 
    return ret; 
}

int main() { 
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> M >> N >> K; 
    for(int i = 0; i < K; i++){
        cin >> x1 >> y1 >> x2 >> y2;  
        for(int i = x1; i < x2; i++){
            for(int j = y1; j < y2; j++){
                a[j][i] = 1; 
            }
        }
    }
    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(a[i][j] != 1 & visited[i][j] == 0) { 
                ret.push_back(dfs(i, j));
            }
        }
    }
    sort(ret.begin(), ret.end());
    cout << ret.size() << "\n";
    for(int a : ret) cout << a << " "; 
    return 0; 
}