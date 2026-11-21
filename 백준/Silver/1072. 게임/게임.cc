#include<bits/stdc++.h>
using namespace std;

long long y, x, ans, first, last, result, mid;

bool calc(int k){
	return (y + k) * 100 / (x + k) > result;
}

int main(){
	cin >> x >> y;
	
	last = 1000000000;
	first = 1;
	result = y * 100 / x; 

	while(first <= last){
//		cout << "first : " << first << " last : " << last << "\n";
		mid = (last + first) / 2;
//		cout << "mid : " << mid << "\n";
		if(calc(mid)) {
			last = mid - 1;
			ans = mid;
			//cout <<"last : " << last << "\n\n";
		}else{
			first = mid + 1;
		}
	}
	
	if(result == (y + ans) * 100 / (x + ans)){
		cout << "-1" << "\n";
	}else{	
		cout << ans << "\n";
	}

	
	return 0;
}