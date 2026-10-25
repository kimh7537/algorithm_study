#include <bits/stdc++.h>

using namespace std;

int arr[1004][1004] = {0,};

vector<int> solution(int n) {
    vector<int> answer;
    
    int head = 1;
    int num = 1;
    int nxt = n;
    int flag = 1;
    int ny = 0, nx = 1;
    
    while(n != 0){
        if(head == 1){
            for(int i = 1 ; i <= n ; i++){
                arr[ny + i][nx] = num;
                num++;
            }
            ny = ny + n;
            n--;
            head = 2;
        }else if(head == 2){
            for(int i = 1 ; i <= n ; i++){
                arr[ny][nx + i] = num;
                num++;
            }
            nx = nx + n;
            n--;
            head = 3;
        }else if(head == 3){
            for(int i = 1 ; i <= n ; i++){
                arr[ny - i][nx] = num;
                num++;
            }
            ny = ny - n;
            nx = flag + 1;
            flag++;
            n--;
            head = 1;
        }
    }
    
    for(int i = 1 ; i <= nxt ; i++){
        for(int j = 1; j <= nxt ; j++){
            if(arr[i][j] != 0){
                answer.push_back(arr[i][j]);
            }
        }
    }
    
    return answer;
}