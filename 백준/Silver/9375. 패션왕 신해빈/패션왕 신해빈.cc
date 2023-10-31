#include <bits/stdc++.h>
using namespace std;

int m, n, result;
string temp1, temp2;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> m;
	for(int i = 0 ; i < m ; i++){
		map<string, int> mp;
		cin >> n;
		for(int i = 0 ; i < n ; i++){
			cin >> temp1 >> temp2;
			mp[temp2]++;
		}
		result = 1;
		for(auto i : mp){
			result *= (i.second+1);
		}
		result -= 1;
		
		cout << result << "\n";
	}
	
	return 0;
}