#include <bits/stdc++.h>
using namespace std;

int n, temp, num, cnt;
vector<int> v;
int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> num;
		v.push_back(num);
	}
	cin >> temp;
	
	for(int i = 0 ; i < n ; i++){
		if(v[i] == temp){
			cnt++;
		}
	}
	
	cout << cnt << "\n";
	
	return 0;
}