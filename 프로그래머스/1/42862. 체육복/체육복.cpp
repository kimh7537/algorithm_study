#include <bits/stdc++.h>

using namespace std;



int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n, 1);
    
    for(int i : reserve){
        student[i - 1]++;
    }
    for(int i : lost){
        if(student[i - 1] > 1) {
            student[i - 1]--;
            continue;
        }
        student[i - 1] = 0;
    }
    
    for(int i = 0 ; i < n ; i++){
        if(student[i] >= 2){
            if(student[i - 1] == 0 && i >= 1) {
                student[i]--;
                student[i - 1]++;
            }else if(student[i + 1] == 0 && i + 1 < n){
                student[i]--;
                student[i + 1]++;
            }
        }
    }
    
    for(auto it : student){
        if(it >= 1) answer++;
    }
    
    return answer;
}