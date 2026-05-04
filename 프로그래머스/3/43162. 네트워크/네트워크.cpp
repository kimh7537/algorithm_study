#include <bits/stdc++.h>

using namespace std;

int visited[204] = {0,};
vector<vector<int>> v;
int num;

void dfs(int k){
    visited[k] = 1;
    for(int i = 0 ; i < num ; i++){
        if(i == k) continue;
        if(visited[i] > 0) continue;
        if(v[k][i] == 0) continue;
        dfs(i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    num = n;
    v= computers;

    for(int i = 0 ; i < num ; i++){
        if(visited[i] == 0){
            dfs(i);
            answer++;
        }
    }
    
    return answer;
}