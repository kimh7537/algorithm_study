#include <bits/stdc++.h>

using namespace std;

int v[104][104];
vector<int> res;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    fill(&v[0][0], &v[103][104], 1e9);
    // memset(v, 987654321, sizeof(v));
    
    for(int i = 1 ; i <= n ; i++){
        v[i][i] = 0;
    }
    
    for(auto it : results){
        v[it[0]][it[1]] = 1;
    }
    
    for(int k = 1 ; k <= n ; k++){
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(v[i][k] != 1e9 && v[k][j] != 1e9 ){
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
                }
            }
        }
    }
    
    for(int i = 1 ; i <= n ; i++){
        int cnt = 0;
        for(int j = 1 ; j <= n ; j++){
            if(v[j][i] != 1e9 && v[j][i] != 0){   // i가 진 상대
                cnt++;
            }
            if(v[i][j] != 1e9 && v[i][j] != 0){   // [수정 1] i가 이긴 상대도 셈
                cnt++;
            }
        }
        if(cnt == n - 1) answer++;                // [수정 2] while문 대신 바로 판정
    }
    
    return answer;
}