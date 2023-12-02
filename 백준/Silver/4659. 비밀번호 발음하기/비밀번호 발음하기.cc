#include <bits/stdc++.h>
using namespace std;

int lcnt, rcnt, is_v;
bool flag;

bool is_Vowel(char a){
	return (a == 'a' || a == 'e' || a =='u' || a=='i' || a=='o');
}

int main(){
	string s;
	while (true){
		cin >> s;
		if(s == "end") break;
		lcnt=rcnt=0;
		flag = false;
		is_v = 0;
		for(int i = 0 ; i < s.size() ; i++){
			if(is_Vowel(s[i]))lcnt++, rcnt = 0, is_v = 1;
			else lcnt = 0, rcnt++;
			
			if(lcnt == 3 || rcnt == 3) flag = 1;
			if(i >= 1 && (s[i] == s[i-1]) && (s[i] != 'e' && s[i] != 'o')) flag = 1;
		}
		
		if(is_v == 0) flag = 1;
		if(flag) cout << "<" << s << ">" << " is not acceptable.\n";
		else cout << "<" << s << ">" << " is acceptable.\n";
		
	}
	
	return 0;
}