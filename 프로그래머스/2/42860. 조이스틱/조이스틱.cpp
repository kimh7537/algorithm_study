#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct Data {
    string s;
    int d, i;
    Data(string str, int distance, int idx) : s(str), d(distance), i(idx) {}
};

int solution(string name) {
    int answer = 0;
    string sbFirst(name.length(), 'A');
    
    queue<Data> que;
    que.push(Data(sbFirst, 0, 0));
    
    while (!que.empty()) {
        Data data = que.front();
        que.pop();
        
        string temp = data.s;
        
        if (abs(name[data.i] - data.s[data.i]) > 13) { // 뒤로 움직이는 게 빠를 때
            data.d += (26 - abs(name[data.i] - data.s[data.i]));
        } else {
            data.d += abs(name[data.i] - data.s[data.i]);
        }
        
        temp[data.i] = name[data.i]; // 문자 변경
        data.s = temp;
        
        // 앞으로 전진
        if (data.i + 1 == name.length()) {
            que.push(Data(data.s, data.d + 1, 0));
        } else {
            que.push(Data(data.s, data.d + 1, data.i + 1));
        }
        
        // 뒤로 후진
        if (data.i - 1 == -1) {
            que.push(Data(data.s, data.d + 1, name.length() - 1));
        } else {
            que.push(Data(data.s, data.d + 1, data.i - 1));
        }
        
        // 정답 찾았을 때
        if (data.s == name) {
            answer = data.d;
            break;
        }
    }
    return answer;
}