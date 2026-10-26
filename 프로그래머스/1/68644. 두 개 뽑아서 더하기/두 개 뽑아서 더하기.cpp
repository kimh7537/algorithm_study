#include <bits/stdc++.h>

using namespace std;

int sum;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    sort(numbers.begin(), numbers.end());
    
    for(int i=0 ; i<numbers.size() ; i++){
        for(int j=i+1 ; j<numbers.size() ; j++){
            sum = numbers[i] + numbers[j];
            answer.push_back(sum);
        }
        sum = 0;
    }
    
    sort(answer.begin(), answer.end());
    
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    
    return answer;
}