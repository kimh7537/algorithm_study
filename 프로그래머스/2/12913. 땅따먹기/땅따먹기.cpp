#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> board;
vector<vector<int>> memo;   // memo[i][j] = -1이면 아직 계산 안 함

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
    board = land;                              // 전역에 한 번만 저장 (복사는 이때 1번)
    memo.assign(n, vector<int>(4, -1));

    int answer = 0;
    for (int j = 0; j < 4; j++)                // 첫 행의 4칸 중 어디서 시작할지
        answer = max(answer, f(0, j));
    return answer;
}