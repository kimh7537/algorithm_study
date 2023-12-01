#include<bits/stdc++.h>
using namespace std;

string s;
vector<char> v = {'a', 'e', 'i', 'o', 'u'};


int main(){
	
	while(cin >> s){
		if(s == "end") break;
		
		bool flag = false;
		
		for(int i = 0 ; i < s.size() ; i++){
			auto a = find(v.begin(), v.end(), s[i]);
			auto b = find(v.begin(), v.end(), s[i+1]);
			auto c = find(v.begin(), v.end(), s[i+2]);
			
			if(a != v.end()){
				flag = true;
			}
			if(i + 2 < s.size()){
				if(a != v.end() && b != v.end() && c != v.end()) {
					flag = false; break;
				}
				if(a == v.end() && b == v.end() && c == v.end()){
					flag = false; break;
				}
			}
			if(i + 1 < s.size()){
				if(s[i] == s[i+1]){
					if(s[i] != 'e' && s[i] != 'o'){
						flag = false; break;
					}
				}
			}
		}
		
		if(flag) cout << "<" << s << ">" << " is acceptable." << "\n";
		else if(flag == false) cout << "<" << s << ">" << " is not acceptable." << "\n";
		
	}
	
	
	return 0;
}
