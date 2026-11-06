#include <bits/stdc++.h>

using namespace std;

long long lo, hi, mid, num;
vector<int> v;

long long check(long long mid){
    long long temp = mid;
    long long res = 0;
    for(auto it : v){
        res += (mid / it);
        //cout << "mid / it : " << mid / it << "\n";
        //cout << "res : " << res << "\n\n";
    }
    
    if(res >= num) return 1;
    else return 0;
}


long long solution(int n, vector<int> times) {
    long long answer = 0;
    v = times;
    num = n;
    lo = *min_element(times.begin(), times.end());
    hi = (long long)*max_element(times.begin(), times.end()) * n;
    //cout << "lo : " << lo << " hi : " << hi <<"\n";
    
    while(lo <= hi){
        mid = (lo + hi) / 2;
        //cout << "mid : " << mid << "\n";
        //cout << "lo : " << lo << " hi : " << hi << "\n";
        if(check(mid)){
            answer = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    
    return answer;
}