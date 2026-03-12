#include<bits/stdc++.h>
using namespace std;

int n, temp, flag = 1;
int ret;
vector<int> v;

int main(){
	
	cin >> n;

	if(n < 100){
		cout << n << "\n";
		return 0;
	}
	
	for(int idx = 100 ; idx <= n ; idx++){
		flag = 0;
		string s = to_string(idx);
		temp = (s[0] - '0') - (s[1] - '0');
		for(int i = 1 ; i < s.size() - 1; i++){
			int mid = (s[i] - '0') - (s[i + 1] - '0');
			if(mid != temp){
				flag = 1;
				break;
			}
		}
		
		if(flag != 1){
			ret++;
		}
	
	}
	
	ret += 99;
	cout << ret << "\n";

	
	return 0;
}