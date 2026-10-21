#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(),
         [](const vector<int>& a, const vector<int>& b) {
             return a[1] < b[1];          // 끝점 기준 오름차순
         });

    int answer = 0;
    int last = 0;                         // 마지막 미사일 위치(끝점 e로 저장)
    for (const auto& t : targets) {
        if (t[0] >= last) {               // 안 맞았으면
            answer++;
            last = t[1];                  // 이 구간 끝 바로 앞에 쏨
        }
    }
    return answer;
}