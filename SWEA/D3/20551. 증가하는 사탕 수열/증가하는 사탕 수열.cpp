#include<bits/stdc++.h>
using namespace std;

int A, B, C, cnt;
vector<int> v;

int main(){
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
		cnt = 0;
        cin >> A >> B >> C;
        if (C < 3|| B < 2){
          	v.push_back(-1);
            continue;
        }
        
        while(B >= C){
            cnt++;
            B--;
        }
        while (A >= B){
            cnt++;
            A--;
        }
        v.push_back(cnt);
    }
    
    for (int i = 0; i < v.size(); i++){
        cout << "#"<<i+1<<" "<< v[i]<<"\n";
    }
	return 0;
}