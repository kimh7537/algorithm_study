#include <bits/stdc++.h>

using namespace std;

long long n, m, num, lo, hi, result;
vector<long long> v;

bool chk(long long mid){
	long long cnt = 0;
	long long temp = 0;
	for(auto it : v){
		if(temp + it > mid){
			cnt++;
			temp = it;
		}else{
			temp += it;
		}
//		cout << "temp : " << temp << " cnt : " << cnt << "\n";
	}
	
	if(temp <= mid) cnt++;
	else return false;
	
	if(cnt <= m) return true;
	else return false;
}

int main(){
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
		cin >> num;
		v.push_back(num);
		lo = max(lo, num);   // 가장 긴 강의
        hi += num;           // 전체 합
	}
	
//	lo = 1;
//	hi = 100000 * 10000;

	while(lo <= hi){
		long long mid = (lo + hi) / 2;
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