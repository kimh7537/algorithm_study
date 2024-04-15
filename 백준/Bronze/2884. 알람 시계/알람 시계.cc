#include <bits/stdc++.h>
using namespace std;

int h, m;

int main(){
	
	cin >> h >> m;
	
	if(m >= 45){
		m -= 45;
	}else{
		m += 60;
		m -= 45;
		if(h == 0){
			h = 23;
		}else{
			h -= 1;
		}
	}
	
	cout << h << " " << m << "\n";
	
	return 0;
}