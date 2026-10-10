#include <bits/stdc++.h>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i] == ' ') {
            answer += s[i];
            continue;
        }
        int num = s[i] + n;
        if('a' <= s[i] && s[i] <= 'z'){
            if(num > 'z') {
                num -= 26;
            }
        }
        else if('A' <= s[i] && s[i] <= 'Z'){
            if(num > 'Z') {
                num -= 26;
            }
        }
        answer += (char)num;
    }
    //cout << (int)'z' << " " << (int)'A';
    return answer;
}