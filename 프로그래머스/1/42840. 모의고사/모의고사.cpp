#include <bits/stdc++.h>

using namespace std;

vector<int> v1, v2, v3;
int n1, n2, n3, cnt1, cnt2, cnt3;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    v1 = {1, 2, 3, 4, 5};
    v2 = {2, 1, 2, 3, 2, 4, 2, 5};
    v3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    n1 = v1.size(); //5
    n2 = v2.size(); //8
    n3 = v3.size(); //10
    
    for(int i = 0 ; i < answers.size() ; i++){
        int temp = answers[i];
        // cout << "temp : " << temp << "\n";
        
        if(temp == v1[i % n1]){
            // cout << 'hello\n';
            cnt1++;
        }
        if(temp == v2[i % n2]){
            // cout << 'hello2\n';
            cnt2++;
        }
        if(temp == v3[i % n3]){
            // cout << 'hello3\n'; 
            cnt3++;
        }
    }
    
    // cout << "cnt1 : " << cnt1 << " cnt2 : " << cnt2 << " cnt3 : " << cnt3 << '\n';
    int temp = max(cnt1, cnt2);
    int temp2 = max(temp, cnt3);
    
    // cout << "temp2 : " << temp2 << "\n";
    
        if(temp2 == cnt1){
            answer.push_back(1);
        }
        if(temp2 == cnt2){
            answer.push_back(2);
        }
        if(temp2 == cnt3){
            answer.push_back(3);
        }
    
    return answer;
}