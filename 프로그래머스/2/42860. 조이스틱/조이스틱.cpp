#include <bits/stdc++.h>

using namespace std;

int result, length, mv, y;

int solution(string name) {
    length = name.size();
    mv = length - 1;
    
    for(int x = 0 ; x < length ; x++){
        result += min(name[x] - 'A', 'Z' - name[x] + 1);
        
        y = x + 1;
        while(y < length && name[y] == 'A'){
            y++;
        }
        mv = min(mv, min(x + x + (length -y), x + (length -y) + (length - y)));
    }
    
    result += mv; 
    
    return result;
}