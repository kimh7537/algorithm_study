#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main(){
	cin >> a >> b >> c;
	
	if(a == b && b == c){
		cout << 10000 + a * 1000 << "\n";
	}
	else if(a == b || b == c || a == c){
		if(a == c) cout << 1000 + a * 100 << "\n";
		else cout << 1000 + b * 100 << "\n";
	}
	else if(a != b && b != c && a != c){
		int ret = max(a, b);
		ret = max(ret, c);
		
		cout << ret * 100 << "\n";
	}
	
	return 0;
}