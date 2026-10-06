#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<pair<long long, long long>> points;
    long long minX = LLONG_MAX, maxX = LLONG_MIN;
    long long minY = LLONG_MAX, maxY = LLONG_MIN;

    int n = line.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long A = line[i][0], B = line[i][1], E = line[i][2];
            long long C = line[j][0], D = line[j][1], F = line[j][2];

            long long denom = A * D - B * C;
            if (denom == 0) continue;                 // 평행 또는 일치

            long long xNum = B * F - E * D;
            long long yNum = E * C - A * F;
            if (xNum % denom != 0 || yNum % denom != 0) continue; // 정수 아님

            long long x = xNum / denom;
            long long y = yNum / denom;
            points.push_back({x, y});

            minX = min(minX, x); maxX = max(maxX, x);
            minY = min(minY, y); maxY = max(maxY, y);
        }
    }

    int width  = maxX - minX + 1;
    int height = maxY - minY + 1;
    vector<string> answer(height, string(width, '.'));

    for (auto& [x, y] : points) {
        answer[maxY - y][x - minX] = '*';
    }
    return answer;
}