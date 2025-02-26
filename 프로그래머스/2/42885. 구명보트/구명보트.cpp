#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int first, second;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    first = 0;
    second = (int)people.size() - 1;
    while(first < second){
        if(people[first] + people[second] <= limit){
            first += 1;
            second -= 1;
            answer++;
        }else if(people[first] + people[second] > limit){
            second -= 1;
            answer++;
        }
    }
    if(first == second){
        answer++;
    }
    
    return answer;
}