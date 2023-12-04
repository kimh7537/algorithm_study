#include <bits/stdc++.h>
using namespace std;

int h,w;
int arr[104][104];

int main(){
	cin >> h >> w;
	string s;
	for(int i = 0 ; i < h ; i++){
		cin >> s;
		for(int j = 0 ; j < w ; j++){
			if(s[j] == 'c') arr[i][j] = 0;
			else arr[i][j] = -1;
		}
	}
	
	for(int i = 0 ; i < h ; i++){
		for(int j = 0 ; j < w-1 ; j++){
			if(arr[i][j] >= 0 && arr[i][j+1] != 0){
				arr[i][j+1] = arr[i][j] +1; 
			}
		}
	}
	
	for(int i = 0 ; i < h ; i++){
		for(int j = 0 ; j < w ; j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	
	
	return 0;
}
