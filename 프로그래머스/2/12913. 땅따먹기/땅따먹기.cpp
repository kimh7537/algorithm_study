#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
int dp[100004][4];
int row;

int go(int k, int idx) {
    if (k == row) return 0;
    
    int& ret = dp[k][idx];
    if (ret != -1) return ret;
    
    int best = 0;
    for (int next = 0; next < 4; next++) {
        if (next == idx) continue; // 같은 열 연속 불가
        best = max(best, go(k + 1, next));
    }
    
    return ret = v[k][idx] + best; // 현재 칸 점수 + 다음 최대값
}

int solution(vector<vector<int>> land) {
    v = land;
    row = land.size();
    memset(dp, -1, sizeof(dp));
    
    int answer = 0;
    for (int i = 0; i < 4; i++) {
        answer = max(answer, go(0, i)); // 첫 행의 4칸 중 최대값
    }
    
    return answer;
}