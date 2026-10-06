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

    // 3단계: '.'으로 꽉 찬 판 만들기
    int width = maxX - minX + 1;    // 가로 칸 수
    int height = maxY - minY + 1;   // 세로 칸 수

    vector<string> answer;
    for (int r = 0; r < height; r++) {
        string row = "";
        for (int c = 0; c < width; c++) {
            row += ".";
        }
        answer.push_back(row);
    }

    // 4단계: 교점마다 '*' 찍기
    for (int i = 0; i < points.size(); i++) {
        long long x = points[i].first;
        long long y = points[i].second;

        int row = maxY - y;   // 맨 위(maxY)에서 몇 칸 아래인가
        int col = x - minX;   // 맨 왼쪽(minX)에서 몇 칸 오른쪽인가
        answer[row][col] = '*';
    }

    return answer;
}