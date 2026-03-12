#include<bits/stdc++.h>
using namespace std;

int arr[10004];

void checkMethod(int i){
	int ret = i;
	int temp = 0;
	while(i > 0){
		temp = i % 10;
//		cout << "temp : " << temp << "\n";
		i /= 10;
//		cout << "i : " << i << "\n";
		ret += temp;
	}
	arr[ret] = 1;
}

int main(){
	
	for(int i = 1 ; i <= 10000 ; i++){
		checkMethod(i);
//		cout << arr[i] << "\n";
		if(arr[i] == 0){
			cout << i << "\n";
		}
	}
	
	return 0;
}