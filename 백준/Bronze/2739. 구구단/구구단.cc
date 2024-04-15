#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
	
	cin >> n;
	
	for(int i = 1 ; i <= 9 ; i++){
		int temp = n * i;
		cout << n << " * " << i << " = " << temp << "\n";
	}
	
	return 0;
}