#include <bits/stdc++.h>
using namespace std;

int n, num;
vector<int> a, b;

int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> num;
		a.push_back(num);
	}
	for(int i = 0 ; i < n ; i++){
		cin >> num;
		b.push_back(num);
	}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	
	int res = 0;
	for(int i = 0 ; i < n ; i++){
		res += a[i] * b[i];
	}
	cout << res << "\n";
	
	return 0;
}