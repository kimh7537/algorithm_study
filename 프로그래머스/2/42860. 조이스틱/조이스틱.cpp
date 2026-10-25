#include <string>
#include <algorithm>
using namespace std;

int solution(string name) {
    int n = name.size();
    int updown = 0;
    int move = n - 1;                       // ① 한 방향으로 쭉

    for (int i = 0; i < n; i++) {
        updown += min(name[i] - 'A', 'Z' - name[i] + 1);

        int next = i + 1;
        while (next < n && name[next] == 'A') next++;   // A 덩어리 끝 찾기

        move = min(move, i * 2 + (n - next));   // ② 오른쪽 먼저 갔다가 되돌아옴
        move = min(move, i + (n - next) * 2);   // ③ 왼쪽 먼저 갔다가 되돌아옴
    }
    return updown + move;
}