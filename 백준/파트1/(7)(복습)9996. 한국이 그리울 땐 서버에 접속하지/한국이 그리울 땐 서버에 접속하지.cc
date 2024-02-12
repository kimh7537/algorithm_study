#include <bits/stdc++.h>
using namespace std;

int n;
string s, s2;

int main(){
	cin >> n;
	cin >> s;
	
	auto it = s.find("*");
	string a1 = s.substr(0, it);
	string a2 = s.substr(it+1);
	
	for(int i = 0 ; i < n ; i++){
		cin >> s2;
		
		if(s2.size() < a1.size() + a2.size()){
			cout << "NE" << "\n";
		}
		else{
			if(s2.substr(0, it) == a1 && s2.substr(s2.size() - a2.size()) == a2){
				cout << "DA" << "\n";      
			}
			else{
				cout << "NE" << "\n";
			}
		}
	}
	
	return 0;
}
