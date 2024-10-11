#include <bits/stdc++.h>
using namespace std;

int n, temp;
vector<int> v, v2;

int main(){
	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		cin >> temp;
		v.push_back(temp);
	}
	
	sort(v.begin(), v.end());
	
	int res = 0;
	for(auto it : v){
		res += it;
		v2.push_back(res);
	}
	 
	int ress = accumulate(v2.begin(), v2.end(), 0);
	cout << ress << '\n';
	
	return 0;
}