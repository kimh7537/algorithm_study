#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto it : commands){
        vector<int> v;
        for(int i = it[0] - 1 ; i < it[1] ; i++){

            v.push_back(array[i]);
        }

        sort(v.begin(), v.end(), less<int>());
        answer.push_back(v[it[2] - 1]);
    }
    
    return answer;
}