#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
	
	cin >> s;
	
//	if(s.find("pi") != string::npos){
//		auto it = s.find("pi");
//		s.erase(it, 2);
//	}
//	if(s.find("ka") != string::npos){
//		auto it = s.find("ka");
//		s.erase(it, 2);
//	}
//	if(s.find("chu") != string::npos){
//		auto it = s.find("chu");
//		s.erase(it, 3);
//	}
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

//	cout << s << "\n";
	
	return 0;
}