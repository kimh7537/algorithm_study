#include <bits/stdc++.h>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == ' ') {
            answer += ' ';
            continue;
        }
        
        char num;
        if('a' <= s[i] && s[i] <= 'z'){
            if(s[i] + n > 'z') {
                num = s[i] + n - 26;
            }else{
                num = s[i] + n;
            }
        }
        else if('A' <= s[i] && s[i] <= 'Z'){
            if(s[i] + n > 'Z') {
                num = s[i] + n - 26;
            }else{
                num = s[i] + n;
            }
        }
        answer += num;
    }

    return answer;
}