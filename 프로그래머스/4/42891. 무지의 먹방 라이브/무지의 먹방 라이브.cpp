#include <bits/stdc++.h>
using namespace std;

int result;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}


int solution(vector<int> food_times, long long k) {
    long long sum = accumulate(food_times.begin(), food_times.end(), 0LL);
    if(sum <= k) return -1;
    
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    int n = food_times.size();
    for(int i = 0 ; i < n ; i++){
        pq.push({food_times[i], i+1});
    }
    
    long long remaining = n;
    long long prev_pos = 0;
    while(!pq.empty()){
        long long current = pq.top().first;
        long long diff = current - prev_pos;
        
        if(k < remaining * diff){
            break;
        }
        
        k -= (remaining * diff);
        pq.pop();
        prev_pos = current;
        remaining--;
    }
    
    vector<pair<int, int>> leftover;
    while(!pq.empty()){
        leftover.push_back(pq.top());
        pq.pop();
    }
    sort(leftover.begin(), leftover.end(), cmp);
    
    result = leftover[k % remaining].second;
    
    return result;
}