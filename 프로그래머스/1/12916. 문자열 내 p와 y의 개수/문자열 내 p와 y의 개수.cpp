#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int numx = 0;
    int numy = 0;

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == 'p' || s[i] == 'P'){
            numx++;
        }else if(s[i] == 'y' || s[i] == 'Y'){
            numy++;
        }
    }
    
    if(numx == 0 && numy == 0) {
        answer = true;
    }else{
        if(numx == numy) answer = true;
        else answer = false;
    }

    return answer;
}