#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());

    int l = 0;
    int r = people.size() - 1;
    int answer = 0;

    while (l <= r) {
        if (people[l] + people[r] <= limit) {
            l++;   // 가장 가벼운 사람도 같이 탑승
        }
        r--;       // 가장 무거운 사람은 항상 탑승
        answer++;  // 보트 1개 사용
    }

    return answer;
}