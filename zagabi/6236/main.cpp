#include<bits/stdc++.h>
using namespace std;

long long n, m, num, lo, hi, mid, result, sum, mx;
vector<int> v;

int chk(int mid){
	
	int temp = mid;
	int k = m;
	k--;
	for(auto it : v){
		if(temp - it >= 0){
			temp -= it;
		}else{
			temp = mid;
			k--;
			temp -= it;
		}
	}
	
	if(k >= 0) return 1;
	else return 0;
}

int main(){
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
        sum += num;
        mx = max(mx, num);
    }
	
	lo = mx;
	hi = sum;
	while(lo <= hi){
		mid = (lo + hi) / 2;
		
		if(chk(mid)){
			result = mid;
			hi = mid - 1;
		}else{
			lo = mid + 1;
		}
	}
	
	cout << result << "\n";

	return 0;
}