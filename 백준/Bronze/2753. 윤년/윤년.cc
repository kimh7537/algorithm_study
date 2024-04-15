#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
	
	cin >> n;
	if(n % 4 == 0 && n % 100 != 0){
		cout << 1 << "\n";
	}else if(n % 4 ==0 && n % 400 == 0){
		cout << 1 << "\n";
	}else{
		cout << 0 << "\n";
	}
	
	return 0;
}