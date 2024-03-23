#include <bits/stdc++.h>
using namespace std;

int k, num, arr[1030], temp;
vector<int> v[11];

void go(int kk, int idx){
	
	if(kk == 1) {
		v[1].push_back(arr[num/2]);
		return;
	}
	int n = (int)pow(2, kk-1);
	for(int i = temp ;; i += idx){
		if(n == 0) break;
		v[kk].push_back(arr[i]);
		n--;
	}
	temp += idx / 2;
	go(kk-1, idx*2);
}

int main(){
	cin >> k;
	num = (int)pow(2, k) - 1;

	for(int i = 0 ; i < num ; i++){
		cin >> arr[i];
	}

	go(k, 2);
	
	for(int i = 1 ; i <= k ; i++){
		for(auto it : v[i]){
			cout << it << " ";
		}
		cout << "\n";
	}
	return 0;
}
