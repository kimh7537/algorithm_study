#include<bits/stdc++.h>

using namespace std;

int first, second;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int s = people.size();
    vector<int> temp(s, 1);

    int r = 0;
    int l = people.size() - 1;
    int num = 0;

    while(r < l){

        //cout << "r : " << r << " l : " << l << "\n";
        num = people[r] + people[l];
        //cout << "num : " << num << "\n";
        if(num > limit){
            l--;
        }else if(num <= limit){
            answer++;
            temp[r] = 0;
            temp[l] = 0;
            int a = 0;
            int b = temp.size() - 1;
            r++;   // a, b 계산 대신
            l--;
        }
    }
    for(int it : temp){
        if(it == 1){
            answer++;
        }
    }

    return answer;
}