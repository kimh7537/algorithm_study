#include <bits/stdc++.h>
using namespace std;

string s;
vector<char> v;

int main(){
	getline(cin, s);
	
	for(int i = 0 ; i < s.size() ; i++){
		
		if('A' <= s[i] && s[i] <= 'Z'){
			if(s[i] + 13 > 90){
				s[i] = (s[i]+13-90-1) + 'A';
				v.push_back(s[i]);
			}else v.push_back(s[i] + 13);
		}
		else if('a' <= s[i] && s[i] <= 'z'){
			if(s[i] + 13 > 122){
				s[i] = (s[i]+13-122-1) + 'a';
				v.push_back(s[i]);
			}else v.push_back(s[i] + 13);
		}
		else{
			v.push_back(s[i]);
		}	
	}
	
	for(char a : v){
		cout << a;
	}
	
	
	return 0;
}
