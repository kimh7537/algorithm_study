#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int board[100001][4];
int memo[100001][4];        // -1이면 아직 계산 안 함

// f(i, j) = i행에서 j열을 밟았을 때, i행부터 마지막 행까지 얻을 수 있는 최대 점수
int f(int i, int j) {
    if (i == n - 1) return board[i][j];        // 기저 사례: 마지막 행
    int &ret = memo[i][j];
    if (ret != -1) return ret;                 // 이미 계산했으면 재사용

    int best = 0;
    for (int k = 0; k < 4; k++)
        if (k != j) best = max(best, f(i + 1, k));   // 다음 행은 같은 열 제외
    return ret = board[i][j] + best;
}

int solution(vector<vector<int>> land) {
    n = land.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
            board[i][j] = land[i][j];

    memset(memo, -1, sizeof(memo));            // 전부 -1로 초기화

    int answer = 0;
    for (int j = 0; j < 4; j++)
        answer = max(answer, f(0, j));
    return answer;
}