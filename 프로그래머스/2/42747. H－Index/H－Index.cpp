#include <bits/stdc++.h>

using namespace std;

vector<int> t;

bool chk(int mid){
    int cnt = 0;
    for(int i = 0 ; i < t.size() ; i++){
        if(t[i] >= mid){
            // cout << "hello\n";
            cnt++;
        }
    }
    
    // cout << "cnt : " << cnt << "\n";
    if(cnt >= mid){
        return true;
    }else{
        return false;
    }
}

int solution(vector<int> v) {
    int answer = 0;
    
    sort(v.begin(), v.end());
    
    t = v;
    
    int lo = 0;
    int hi = *(v.end() - 1);
    
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        // cout << "mid : " << mid << "\n";
        if(chk(mid)){
            answer = mid;
            lo = mid + 1;
            // cout << "answer : " << answer << "\n";
        }
        else{
            hi = mid - 1;
        }
    }
    
    
    return answer;
}