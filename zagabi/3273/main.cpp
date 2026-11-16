#include <bits/stdc++.h>

using namespace std;

int n, x, num, lo, hi, cnt;
vector<int> v;


int main(){
	
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> num;
		v.push_back(num);
	}
	cin >> x;
	
	sort(v.begin(), v.end());
	
	lo = 0;
	hi = v.size() - 1;
	
	while(lo < hi){
		int temp = v[lo] + v[hi];
		if(temp == x) {
			cnt++;
			hi -= 1;
		}else if(temp > x){
			hi -= 1;
		}else if(temp < x){
			lo += 1;
		}
	}
	
	cout << cnt << "\n";
	
	return 0;
}