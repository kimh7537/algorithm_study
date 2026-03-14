#include <bits/stdc++.h>

using namespace std;
int solution(vector<vector<int>> sizes) {
    int max_w = 0; // 가로(더 긴 쪽)의 최댓값
    int max_h = 0; // 세로(더 짧은 쪽)의 최댓값

    for (const auto& card : sizes) {
        // 명함의 두 변 중 큰 값을 w, 작은 값을 h로 설정
        int w = max(card[0], card[1]);
        int h = min(card[0], card[1]);

        // 각 그룹에서 가장 큰 값을 갱신
        max_w = max(max_w, w);
        max_h = max(max_h, h);
    }

    return max_w * max_h;
}