#include <bits/stdc++.h>
using namespace std;

int n;
string ret;
vector<string> v;
bool cmp(string a, string b){
	if(a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

void go(){
	while(true){
		if(ret.front() == '0') ret.erase(ret.begin());
		else break;
	}
	if(ret.size()) v.push_back(ret);
	else v.push_back("0");
}


int main(){
	cin >> n;
	string s;
	for(int i = 0 ; i < n ; i++){
		cin >> s;
		ret = "";
		for(int j = 0 ; j < s.size() ; j++){
			if(s[j] < 65) ret += s[j];
			else{
				if(ret.size()){
					go();
					ret="";
				}
			}
		}
		if(ret.size()) go();
	}	
	
	sort(v.begin(), v.end(), cmp);
	
	for(string a : v){
		cout << a << "\n";
	}
	
	return 0;
}