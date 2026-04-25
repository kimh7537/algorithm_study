#include<bits/stdc++.h>
using namespace std;

int n, m;
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int visited[104][104] = {0,};

void bfs(vector<vector<int>> maps){
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] += 1;
    
    while(q.size() > 0){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(visited[ny][nx] > 0) continue;
            if(maps[ny][nx] == 0) continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }

}

int solution(vector<vector<int> > maps){
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    
    bfs(maps);
    
    if(visited[n-1][m-1] == 0){
        answer = -1;
    }else if(visited[n-1][m-1] >= 1){
        answer = visited[n-1][m-1];
    }
    
    return answer;
}