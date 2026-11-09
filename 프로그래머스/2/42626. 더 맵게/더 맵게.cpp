#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for(auto it : scoville){
        pq.push(it);
    }
    
    while(pq.size() >=2){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        
        if(a >= K){
            break;
        }
        
        int temp = a + (b * 2);
        pq.push(temp);
        answer++;
    }
    
    if(pq.top() < K) answer = -1;

    
    return answer;
}