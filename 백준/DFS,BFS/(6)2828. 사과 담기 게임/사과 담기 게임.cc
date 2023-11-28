#include <bits/stdc++.h>
using namespace std;

int arr[24];
int N, M, J, cnt, num;

int main(){
	cin >> N >> M;
	cin >> J;
	for(int i = 0 ; i < J ; i++){
		cin >> arr[i];
	}
	
	int left = 1; 
	int right = M;
	for(int i = 0 ; i < J ; i++){
		num = arr[i];
		if(right < num){
			cnt += (num - right);
			right = num;
			left = right - (M-1);
		}
		else if(left > num){
			cnt += (left - num);
			left = num;
			right = left + (M-1);
		}
	}
	
	cout << cnt;
	
	return 0;
}
