#include <bits/stdc++.h>

using namespace std;
vector<int> v;

string solution(string s, int k) {
    string answer = "";
    int idx = 0;
    int mx = -1;
    int temp = 0;
    int flag = 0;
    while(k > 0){
        for(int i = 0 ; i <= k ; i++){
            if(mx < s[idx + i] - '0'){
                mx = s[idx + i] - '0';
                //cout << "mx : " << s[idx + i] - '0' << "\n";
                temp = k - i;
                //cout << "temp : " << temp << "\n";
                flag = i;
                //cout << "flag : " << flag << "\n";
                //cout << "idx : " << idx << "\n\n";
            }
        }
        v.push_back(idx + flag);
        mx = -1;
        idx = idx + flag + 1;
        flag = 0;
        k = temp;
        
        if(v.size() == s.size() - k){
            idx = 1e9;
            break;
        }
    }
    //cout << "idx : " << idx << "\n";
    for(auto it : v){
        answer += s[it];
    }
    for(int i = idx ; i < s.size() ; i++){
        answer += s[i];
    }
    
    
    return answer;
}