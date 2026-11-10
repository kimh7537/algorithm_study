#include <bits/stdc++.h>

using namespace std;

vector<int> adj[20004];
int visited[20004];

void bfs(int start){
    visited[start] = 0;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int nxt = q.front();
        q.pop();
        
        for(int v : adj[nxt]){
            
            if(visited[v] != -1) continue;
            q.push(v);
            visited[v] = visited[nxt] + 1;
        }
    }
    
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    memset(visited, -1, sizeof(visited));
    
    for(auto it : edge){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    
    bfs(1);
    
    int temp = *max_element(visited, visited+20004);
    
    for(int i = 1 ; i < 7 ; i++){
        cout << visited[i] << " ";
    }
    
    for(auto it : visited){
        if(it == temp){
            answer++;
        }
    }
    
    return answer;
}