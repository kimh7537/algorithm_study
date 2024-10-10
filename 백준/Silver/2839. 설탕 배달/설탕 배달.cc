#include<bits/stdc++.h>
using namespace std;

int n, temp = 9999;

int main(){
	
	cin >> n;
	
	int tmp = n;
	int mi = 5000;
	int cnt = 0;
	
	for(;;){
		
		tmp = n - (5 * cnt);
		if(tmp < 0){
			break;
		}
		if(tmp % 3 == 0){
			temp = tmp / 3;
			temp += cnt;
		}else if(tmp == 0){
			temp = cnt;
		}
		cnt++;
		
		mi = min(mi, temp);
//		cout << mi << "\n";
//		cout << "n : " << n << "\n";
	}
	
	if(mi == 5000){
		cout << -1 << "\n";
	}else{
		cout << mi << "\n";
	}
	
	
	return 0;
}