#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> food_times, long long k) {
    long long total = accumulate(food_times.begin(), food_times.end(), 0LL);
    if (total <= k) return -1;  // 더 이상 먹을 음식이 없으면 -1 반환

    // (음식 섭취 시간, 원래 인덱스) 형태로 저장하는 최소 힙
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int n = food_times.size();
    for (int i = 0; i < n; i++) {
        pq.push({food_times[i], i + 1});  // 인덱스를 1부터 시작하도록 저장
    }

    long long prev_time = 0;  // 이전에 제거한 음식의 소요 시간
    long long remaining = n;  // 남은 음식 개수

    while (!pq.empty()) {
        long long current_time = pq.top().first;  // 현재 가장 적은 소요 시간
        long long time_diff = current_time - prev_time;  // 이전 값과의 차이

        if (k < time_diff * remaining) {
            break;  // 더 이상 그룹 단위로 제거할 수 없으면 종료
        }

        k -= time_diff * remaining;  // 그룹 단위로 k에서 시간 차감
        prev_time = current_time;
        pq.pop();
        remaining--;
    }

    // 남은 음식들 중에서 k번째 찾기 (원래 인덱스 순서대로 정렬)
    vector<pair<int, int>> leftover;
    while (!pq.empty()) {
        leftover.push_back(pq.top());
        pq.pop();
    }

    sort(leftover.begin(), leftover.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    return leftover[k % remaining].second;  // 남은 음식 중 k번째의 원래 인덱스 반환
}
