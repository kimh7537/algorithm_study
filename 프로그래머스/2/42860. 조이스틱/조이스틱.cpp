#include <string>
#include <vector>

using namespace std;

int y;

int solution(string name) {
    int answer = 0;
    
    int len = name.length();
    int mv = len - 1;
    
    for(int x = 0 ; x < len ; x++){
        answer += min(name[x] - 'A', 'Z' - name[x] + 1);
        
        y = x + 1;
        while(y < len && name[y] == 'A'){
            y++;
        }
        
        mv = min(mv, min(x + x + len - y, len-y+len-y+x));    
    }
    answer += mv;
    
    return answer;
}