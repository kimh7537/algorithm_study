#include<bits/stdc++.h>
using namespace std;

int n;
string a;
vector<string> v;

bool cmp(string a, string b){
	if(a.size() == b.size()) return a < b;
	
	return a.size() < b.size();
}
void go(){   
	while(true){  
		if(a.size() && a.front() == '0')a.erase(a.begin()); 
		else break;
	}
	if(a.size() == 0) a = "0"; 
	v.push_back(a);
	a = "";  
}
int main(){
	
	cin >> n;
	string s;
	
	for(int i = 0 ; i < n ; i++){
		cin >> s;
		
		int prev = s[0] - '0';
		if(0<=prev && prev<=9) a = s[0];
		else a = "";
		for(int j = 1 ; j < s.size() ; j++){
			int temp = s[j] - '0';
			if(0<=temp && temp<=9){
				if(0<=prev && prev<=9) {
					a += s[j];
				}
				else a = s[j];
			}
			else{
				if(0<=prev && prev<=9) {
					while(true){  
						if(a.size() && a.front() == '0')a.erase(a.begin()); 
						else break;
					}
					if(a.size() == 0) a = "0"; 
					v.push_back(a);
					a = "";
				}
			}
			prev = temp;
		}
		if(0<=prev && prev<=9) {
			while(true){  
				if(a.size() && a.front() == '0')a.erase(a.begin()); 
				else break;
			}
			if(a.size() == 0) a = "0";
			v.push_back(a);
		}
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(auto i : v){
		cout << i << "\n";
	}
	
	return 0;
}
