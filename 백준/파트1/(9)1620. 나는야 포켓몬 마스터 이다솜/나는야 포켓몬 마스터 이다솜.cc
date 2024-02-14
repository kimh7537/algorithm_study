#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;
map<string, int> mp;
map<int, string> mp2;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
		cin >> s;
		mp.insert({s, i+1});
		mp2.insert({i+1, s});
	}
	
	for(int i = 0 ; i < m ; i++){
		cin >> s;
		if(atoi(s.c_str()) == 0){
      auto it = mp.find(s);
			cout << (*it).second << "\n";
		}else {
      auto it = mp2.find(atoi(s.c_str()));
			cout << (*it).second << "\n";
		}
	}
	return 0;
}
