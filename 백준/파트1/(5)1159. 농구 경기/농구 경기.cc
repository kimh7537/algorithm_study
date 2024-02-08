#include <bits/stdc++.h>
using namespace std;

int num;
vector<char> v;
string s;
map<char, int> mp;

int main(){
	
	cin >> num;
	for(int i = 0 ; i < num ; i++){
		cin >> s;
		v.push_back(s[0]);
	}
	
	for(char ch : v){
		if(mp.find(ch) != mp.end()){
			mp[ch] += 1;
		}
		else{
			mp.insert({ch, 1});
		}
	}
	int flag = 0;
	for(auto it = mp.begin() ; it != mp.end() ; it++){
		if((*it).second >= 5){
			flag = 1;
			cout << (*it).first;
		}
	}
	
	if(flag == 0){
		cout << "PREDAJA";
	}
	return 0;
}
