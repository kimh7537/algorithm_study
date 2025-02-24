#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.size();
    int minMove = n-1;
    for(int x = 0; x < n; x++){
        int y = x + 1; // x 오른쪽에 있으면서 A가 아닌 문자가 있는 위치를 y라하자
        while( y < n && name[y] == 'A') y++;
        minMove = min( minMove, min( x+x+(n-y), x+(n-y)+(n-y) ) );
    }
    
    for(int i = 0 ; i < name.size() ; i++){
        if(name[i] - 'N' <= 0) answer += (name[i] - 'A');
        else if(name[i] - 'N' > 0) answer += ('Z' - name[i] + 1); 
    }
    
    return answer + minMove;
}