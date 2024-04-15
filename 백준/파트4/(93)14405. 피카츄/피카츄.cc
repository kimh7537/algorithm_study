#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
	
	cin >> s;
	
	bool flag = 0;
	
	while(s.size()){
		
		flag = 0;
		
		if(s[0] == 'p' && s[1] == 'i'){
			s.erase(0, 2);
		}else if(s[0] == 'k' && s[1] == 'a'){
			s.erase(0, 2);
		}else if(s[0] == 'c' && s[1] == 'h' && s[2] == 'u'){
			s.erase(0, 3);
		}else{
			flag = 1;
			break;
		}
	}
	
	if(flag) {
		cout << "NO" << "\n";
	}else{
		cout << "YES" << "\n";
	}
	
	return 0;
}
