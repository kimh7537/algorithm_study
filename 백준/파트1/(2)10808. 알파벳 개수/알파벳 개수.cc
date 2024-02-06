#include <bits/stdc++.h>
using namespace std;

int arr[30];

int main(){
	string s;
	cin >> s;
	
	for(int i = 0 ; i < s.size() ; i++){
		int num = s[i] - 'a';
		arr[num]++;
	}
	
	for(int i = 0 ; i < 26 ; i++){
		cout << arr[i] << " ";
	}
	
	
	return 0;
}
