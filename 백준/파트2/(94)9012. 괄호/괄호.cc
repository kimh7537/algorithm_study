#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main() {
	cin >> t;
	
	for(int i = 0 ; i < t ; i++){
		cin >> s;
		stack<char> stk;
		for(int j = 0 ; j < s.size() ; j++){
			if(stk.size() == 0){
				stk.push(s[j]);
			}
			else{
				if(stk.top() == '(' && s[j] == ')'){
					stk.pop();
				}else{
					stk.push(s[j]);
				}
			}
		}
		if(stk.size() == 0) cout << "YES" << "\n";
		else cout << "NO" << "\n";
		
	}
	
	return 0;
}
