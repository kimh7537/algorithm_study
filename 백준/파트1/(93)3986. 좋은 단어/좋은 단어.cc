#include <bits/stdc++.h>
using namespace std;

int n, cnt;
char c;
string s;

int main(){
	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		stack<char> stk;
		cin >> s;
		for(int j = 0 ; j < s.size() ; j++){
			if(!stk.empty()){
				c = stk.top();
				if(c == s[j]) stk.pop();
				else stk.push(s[j]);
			}
			else{
				stk.push(s[j]);
			}
		}
		if(stk.empty()) cnt++;
	}
	cout << cnt << "\n";
	

	return 0;
}
