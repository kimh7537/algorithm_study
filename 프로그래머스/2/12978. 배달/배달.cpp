#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adj[54];
int dist[54];

void dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({0, start});
    dist[start] = 0;
    
    while(!pq.empty()){
        int here_cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(dist[u] < here_cost) continue;
        
        for(auto [v, weight] : adj[u]){
            // cout << "v : " << v << " weight : " << weight << "\n";
            int new_cost = here_cost + weight;
            // cout << "new cost : " << new_cost << "\n";
            // cout << "dist[v] : " << dist[v] << "\n";
            if(new_cost < dist[v]){
                // cout << "hello" << "\n";
                dist[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    for (auto it : road) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});   // 반대 방향도 추가
    }
    
    for(int i = 1 ; i <= 50 ; i++){
        dist[i] = 1e9;
    }
    
    dijkstra(1);
    
    for(int i = 1 ; i <= 50 ; i++){
        // cout << dist[i] << "\n";
        if(dist[i] <= K){
            answer++;
        }
    }

    return answer;
}