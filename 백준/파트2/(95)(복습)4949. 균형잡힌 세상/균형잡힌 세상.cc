#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
	
	while(getline(cin, s)){
		
		if(s == ".") break;
		
		bool flag = 0;
		stack<char> stk;
		int temp = s.size();

		for(int i = 0 ; i < s.size() ; i++){
			
			if(s[i] == '(' || s[i] == '[') stk.push(s[i]);
			else if(s[i] == ')' || s[i] == ']'){
				if(!stk.empty()){ //스택이 비지 않음 
					if(stk.top() == '(' && s[i] == ')') stk.pop();
					else if(stk.top() == '[' && s[i] == ']') stk.pop();
					else {
						flag = 1;
						break;
					}
				}
				else if(stk.empty()){  //스택이 비었음 
					flag = 1;
					break;
				}
			}
		}
		if(!stk.empty()) flag = 1;
		
		if(flag) cout << "no\n";
		else cout << "yes\n";
		
	}
	
	
	return 0;
}
