#include <bits/stdc++.h>
using namespace std;

int x, cnt;
int main(){
	cin >> x;
	int num = 1 << 6;
	
	for(int i = 0 ; i < 7 ; i++){
		if(x & (1 << i)){
			cnt++;
		}
	}
	cout << cnt << "\n";
	
	return 0;
}
