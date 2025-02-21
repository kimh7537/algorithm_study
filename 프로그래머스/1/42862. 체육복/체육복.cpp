#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> v(n+2, 1);
    
    for(auto it : lost){
        v[it]--;
    }
    for(auto it : reserve){
        v[it]++;
    }
    
    for(int i = 1 ; i < n+1 ; i++){
        if(v[i] == 0 && v[i-1] > 1){
            v[i-1]--;
            v[i]++;
        }else if(v[i] == 0 && v[i+1] > 1){
            v[i+1]--;
            v[i]++;
        }
    }
    for(int i = 1 ; i < n+1 ; i++){
        if(v[i] >= 1) answer++;
    }
    
    // for(auto it : v){
    //     cout << it << " ";
    // }
    
    return answer;
}