#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000; 
int visited[MAX+4];
long long cnt[MAX+4];
int main() {
    int n, m;
    cin >> n >> m;
    if(n == m){  //반례 생각할 때(최소, 최대, 같은거 등등 생각하기), 주어진 두 값이 같은 경우
        puts("0"); puts("1");
        return 0; 
    } 
    
    visited[n] = 1;
    cnt[n] = 1;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int next : {now-1, now+1, now*2}) {
            if (0 <= next && next <= MAX) { 
                if (!visited[next]) {
                    q.push(next); 
                    visited[next] = visited[now] + 1;  //최단거리(시간) 탐색, 시간은 -1해주기
                    cnt[next] += cnt[now];             //next라는 지점까지 갈 수 있는 경우의 수
                } else if (visited[next] == visited[now] + 1) {  //next를 이미 방문했고, 다시 방문할때 next지점까지 최소시간인지 아닌지 판별
                    cnt[next] += cnt[now];
                }
            }
        }
    }
    cout << visited[m] - 1 << '\n';
    cout << cnt[m] << '\n';
    return 0;
}
