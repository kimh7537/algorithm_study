#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
    int n = name.size();
    int min_move = n - 1;  // 기본적으로 오른쪽으로 쭉 가는 경우
    int total_change = 0;
    
    // 문자 변경 횟수 계산
    for (int i = 0; i < n; i++) {
        // 알파벳 변경 횟수
        total_change += min(name[i] - 'A', 'Z' - name[i] + 1);
        
        // 이동 경로 최적화
        int next = i + 1;
        while (next < n && name[next] == 'A') {
            next++; // 연속된 A는 건너뛰기
        }
        min_move = min(min_move, i + n - next + min(i, n - next));
    }
    
    return total_change + min_move;
}
