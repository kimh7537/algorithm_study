#include <bits/stdc++.h>
using namespace std;
int n, m;
int j;
int res;

int main(){
	cin >> n >> m;
	cin >> j;
	
	int left = 1, right;
	
	for(int i = 0 ; i < j ; i++){
		right = left + m - 1;
		
		int temp;
		cin >> temp;
		
		if(left <= temp && temp <= right){
			continue;
		}
		if(left > temp){
			res += left - temp;
			left = temp;
		}else if(left < temp){
			res += temp - right;
			left += temp - right;
		}
	}
	cout << res;
	
	return 0;
}