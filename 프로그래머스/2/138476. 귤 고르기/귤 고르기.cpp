#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}

int solution(int k, vector<int> v) {
    int answer = 0;
    
    for(auto it : v){
        mp[it] += 1;
        // if(mp.find(it) != mp.end()){
        //     mp[it]++;
        // }else{
        //     mp[it] = 1;
        // }
    }
    
    vector<pair<int, int>> temp;
    for(int i = 1 ; i <= mp.size() ; i++){
        temp.push_back({mp[i], i});
    }
    
    sort(temp.begin(), temp.end(), cmp);
    
    for(auto it : temp){
       // cout << it.first << " " << it.second << "\n";
        if(k >= it.first){
            k -= it.first;
            answer++;
            if(k == 0) break;
        }else{
            answer++;
            break;
        }
        //cout << "k : " << k << "\n";
    }
     
    return answer;
}