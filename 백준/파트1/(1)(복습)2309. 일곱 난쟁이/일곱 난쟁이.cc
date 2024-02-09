#include <bits/stdc++.h>
using namespace std;

int temp, sum, res;
vector<int> v;

int main(){
	for(int i=0 ; i < 9 ; i++){
		cin >> temp;
		v.push_back(temp);
	}
	
	sum = accumulate(v.begin(), v.end(), 0);
	
	for(int i=0 ; i < 9 ; i++){
		for(int j=i+1 ; j < 9 ; j++){
			res = v[i] + v[j];
			if(sum - res == 100){
				v.erase(v.begin() + j);
				v.erase(v.begin() + i);
				
				sort(v.begin(), v.end());
				for(int a : v) cout << a << "\n";
				return 0;
			}
		}
	}
	
	return 0;
}
