#include <bits/stdc++.h>
using namespace std;

int n, k, temp,res, start;
vector<int> v;

int main(){
	
	cin >> n >> k;
	for(int i = 0 ; i < n ; i++){
		cin >> temp;
		v.push_back(temp);
		if(temp <= k){
			start++;
		}
	}
	
	start--;
	while(k > 0){
		if(k - v[start] >= 0) {
			res++;
			k -= v[start];
		}
		else{
			start--;
		}
	}
	
	cout << res << "\n";
	
	return 0;
}