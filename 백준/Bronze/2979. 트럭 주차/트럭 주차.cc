#include <bits/stdc++.h>
using namespace std;

int arr[104];
int a, b, c;

int main(){
	cin >> a >> b >> c;
	int temp1, temp2;
	for(int i = 0 ; i < 3 ; i++){
		cin >> temp1 >> temp2;
		for(int j=temp1+1 ; j <= temp2 ; j++){
			arr[j] += 1;
		}
	}
	
	int ret = 0;
	for(int i : arr){
		if(i == 1) ret += a;
		else if(i == 2) ret += (b * 2);
		else if(i == 3) ret += (c * 3); 
	}
	
	cout << ret << "\n";
	
	return 0;
}