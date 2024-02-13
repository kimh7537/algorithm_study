#include <bits/stdc++.h>
using namespace std;
 
int arr[1000001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int N;
    cin >> N;
    stack<int> stk;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr[i] = num;
        while (1) {
            // 스택이 비었으면 바로 push
            if (stk.empty()) {
                stk.push(i);
                break;
            }
          
            // 스택이 비지 않았으면 스택의 Top과 비교
            int idx = stk.top();
            // num이 더 클 경우에는 index에 해당하는 원소에 num을 넣어주고 Pop
            if (num > arr[idx]) {
                arr[idx] = num;
                stk.pop();
            }
            // num이 작거나 같으면 스택에 push하고 다음 원소 확인
            else {
                stk.push(i);
                break;
            }
        }
    }
    // 스택에 남아 있는 index들에 해당하는 원소는 더 큰 수가 없으므로 -1을 넣어줌
    while (!stk.empty()) {
        int idx = stk.top();
        arr[idx] = -1;
        stk.pop();
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}
