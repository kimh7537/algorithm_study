#include<bits/stdc++.h>

using namespace std;

int first, second, num = -1, idx;
vector<int> v;

string solution(string number, int k) {
    string answer = "";

    first = 0, second = k;
    
    while(k > 0 && second < number.size()){
        idx = 0;
        num = -1;
        for(int i = first ; i <= second ; i++){
            if(number[i] - '0' >  num){
                num = number[i] - '0';
                idx = i;
            }
        }
        k -= (idx - first);
        v.push_back(idx);
        first = idx + 1;
        second = second + 1;
    }
    
    for(auto it : v){
        answer += number[it];
        idx = it;
    }
    if(v.size() < number.size()){
        if(k == 0) answer += number.substr(idx+1);
    }
    
    return answer;
}