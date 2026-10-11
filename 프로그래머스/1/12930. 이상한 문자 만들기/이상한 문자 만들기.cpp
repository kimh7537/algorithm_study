#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    int temp = 0;
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == ' ') {
            temp = 0;
            answer += ' ';
            continue;
        }
        
        if(temp % 2 == 0){
            if('a' <= s[i] && s[i] <= 'z'){
                answer += (s[i] - 32);
            }else{
                answer += s[i];
            }
            
        }else{
            if('A' <= s[i] && s[i] <= 'Z'){
                answer += (s[i] + 32);
            }else{
                answer += s[i];
            }
        }
        temp++;
        
    }
    
    return answer;
}