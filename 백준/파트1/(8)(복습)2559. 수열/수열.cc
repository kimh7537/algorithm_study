#include <bits/stdc++.h>
using namespace std;
int n, m, temp;
int psum[100004];
vector<int> v;

int main(){
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++){
		cin >> temp;
		psum[i] = psum[i-1] + temp;
	}
	for(int i = 0 ; i <= n-m ; i++){
		v.push_back(psum[i + m] - psum[i]);
	}
	int max = *max_element(v.begin(), v.end());
	cout << max << '\n';
    
	return 0;
}
