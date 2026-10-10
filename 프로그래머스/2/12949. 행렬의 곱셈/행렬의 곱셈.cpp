#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    vector<int> temp;
    int cnt = 0;
    
    for(int i = 0 ; i < arr1.size() ; i++){
        temp.clear();
        for(int j = 0 ; j < arr2[0].size() ; j++){
            cnt = 0;
            for(int k = 0 ; k < arr2.size() ; k++){
                cnt += arr1[i][k] * arr2[k][j];
            }
            temp.push_back(cnt);
        }
        answer.push_back(temp);
    }
    
    return answer;
}