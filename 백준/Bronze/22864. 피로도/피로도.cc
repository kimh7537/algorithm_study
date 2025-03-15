#include<bits/stdc++.h>
using namespace std;

int a, b, c, m, temp, res;

int main(){
	
	cin >> a >> b >> c >> m;
	
//	if(a > m) {
//		cout << 0 << "\n";
//		return 0;
//	}
	
	int n = 0;
	while(n < 24){
		if(temp + a <= m) {
			temp += a;
			res += b;
		}else {
			temp -= c;
			if(temp < 0) temp = 0;
		}
		n++;
	}
	
	cout << res << "\n";
	
	return 0;
}