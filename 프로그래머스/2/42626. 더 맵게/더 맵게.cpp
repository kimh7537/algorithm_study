#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for(auto it : scoville){
        pq.push(it);
    }
    
    while(pq.top() < K){
        if(pq.size() == 1) {
            answer = -1;
            break;
        }
        int n1 = pq.top();
        pq.pop();
        int n2 = pq.top();
        pq.pop();
        int temp = n1 + (n2 * 2);
        pq.push(temp);
        answer++;
    }
    
    
    
    return answer;
}