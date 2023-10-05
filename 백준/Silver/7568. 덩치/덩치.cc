#include <bits/stdc++.h>
using namespace std;

int main() {
    int num;
    int rank = 1;
    
    pair<int,int> a[50];
    cin >> num;
    
    for(int i = 0; i < num; i++)
        cin >> a[i].first >> a[i].second;
        
    for(int i = 0; i < num; i++){
        for(int j = 0; j < num; j++)
            if(a[i].first < a[j].first && a[i].second < a[j].second)
                rank++;
        cout << rank << ' ';
        rank = 1;
    }
}