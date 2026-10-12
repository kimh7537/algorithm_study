#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int sum;

int cal(int n, int num){
    int temp = 1;
    for(int i = 0 ; i < num - 1 ; i++){
        temp *= 3;
    }
    return temp * n;
}

int solution(int n) {
    int answer = 0;
    

    while(n >= 3){
        v.push_back(n % 3);        
        n /= 3;
    }
    v.push_back(n);
    
    int num = v.size();
    for(int i = 0 ; i < v.size() ; i++){
        sum += cal(v[i], num);
        num--;
    }
    
    return sum;
}