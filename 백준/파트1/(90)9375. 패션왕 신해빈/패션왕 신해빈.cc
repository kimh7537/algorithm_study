#include <bits/stdc++.h>
using namespace std;

int n, m;
string s1, s2;
map<string, int> mp;

int main(){
	cin >> n;
	for(int i=0 ; i < n ; i++){
		cin >> m;
		for(int j=0 ; j < m ; j++){
			cin >> s1 >> s2;
			mp[s2]++;
		}
		int result = 1;
		for(auto it : mp){
			result *= (it.second+1);
		}
		result -= 1;
		cout << result << "\n";
		mp.clear();
	}
	
	return 0;
}
