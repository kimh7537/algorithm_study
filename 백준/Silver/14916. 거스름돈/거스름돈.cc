#include <bits/stdc++.h>
using namespace std;

int main(){
	int num, cnt = 0;
	
	cin >> num;
	if(num % 5 == 0){
		cout << num/5;
	}else{
		while(num > 0){
			num -= 2;
			cnt++;
			if(num % 5 == 0){
				cout << cnt + num/5;
				break;
			}
		}
	}
	
	if(num < 0){
		cout << -1;
	}
	
	return 0;
}