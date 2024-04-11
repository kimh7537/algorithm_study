#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main(){
	
	cin >> a >> b;
	cin >> c;
	
	int t1, t2;
	
	if(b + c >= 60) {
		t1 = (b + c) / 60;
		t2 = (b + c) % 60;
		
		if(t1 + a >= 24) {
			a = t1 + a - 24;
		}else{
			a = a + t1;
		}
		
	}else{
		t2 = b + c;
	}
	
	cout << a << " " << t2 << "\n";
	
	return 0;
}