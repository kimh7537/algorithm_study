#include <bits/stdc++.h>
using namespace std;

vector<string> v;
string pattern;
string a;
int filenum;

int main(){
	cin >> filenum;
	cin >> pattern;
	
	for(int i = 0 ; i < filenum ; i++){
		cin >> a;
		v.push_back(a);
	}
	
	auto it = pattern.find('*');
	string front = pattern.substr(0, it);   
	string back = pattern.substr(it+1); 
	
	for(string s : v){
		if(front.size() + back.size() > s.size()){
			cout << "NE" << "\n";
		}else{
			if(s.substr(0, it) == front && s.substr(s.size() - back.size()) == back){
				cout << "DA" << "\n";      
			}
			else{
				cout << "NE" << "\n";
			}
		}
		
	}

	return 0;
}
