#include <bits/stdc++.h>
using namespace std;
int T, N, x;
string P, order;
int main(){ 

    cin >> T;  
    for(int t = 0; t < T; t++){ 
        deque<int> D;
        cin >> P >> N >> order;
        x = 0;
        for(char c : order){
            if(c == '[' || c == ']') continue;
            if(c >= '0' && c <= '9') x = x*10 + c-'0';
            else{
                if(x > 0) D.push_back(x); //if문 없어도 됨
                x = 0; 
            }
	} 
	if(x > 0) D.push_back(x);//if문이 없으면 배열에 숫자가 없어도 x초기값 0이 deque에 들어가게 됨, if문 없을때 반례 : 1 R 0 []   정답:[], 실제정답:[]

        bool error = false, rev = false;
 	for(char a : P){
 		if(a == 'R') rev = !rev; 
 		else{
                	if(D.empty()){
                    		error = true;
                    		break;
                	}
                	if(rev) D.pop_back();
                	else D.pop_front(); 
		}
	}  

        if(error) cout << "error" << '\n';
        else{
        	cout << "["; 

            	if(rev) reverse(D.begin(), D.end());
            	for(int i = 0; i < D.size(); i++){
        		cout << D[i];  
                	if(i < D.size()-1) cout << ",";
            	}
        	cout << "]\n";  
        }
    }
} 
