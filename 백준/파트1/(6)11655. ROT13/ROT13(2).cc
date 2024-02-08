#include<bits/stdc++.h>
using namespace std;   
string s; 
int main(){
    getline(cin, s); 
    for(int i = 0; i < s.size(); i++){
        // 대문자인경우
        if(s[i] >= 65 && s[i] < 97){ //97이 아닌 <= 90으로 해도 무방함
            if(s[i] + 13 > 90) s[i] = s[i] + 13 - 26;   //범위를 넘어가고 알파벳 갯수 26개를 마지막에서 빼주면 처음으로 돌아가는 원리
            else s[i] = s[i] + 13;  
        }else if(s[i] >= 97 && s[i] <= 122){
            if(s[i] + 13 > 122)s[i] = s[i] + 13 - 26; 
            else s[i] = s[i] + 13;  
        }
        cout << s[i];  
    } 
    return 0; 
}
