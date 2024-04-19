#include <bits/stdc++.h>
using namespace std;

int x, n, a, b, temp, sum;

int main(){
	cin >> x;
	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		cin >> a >> b;
		temp = a * b;
		sum += temp;
	}
	
	if(sum == x) cout << "Yes" << "\n";
	else cout << "No" << "\n";
	
	
	
	return 0;
}