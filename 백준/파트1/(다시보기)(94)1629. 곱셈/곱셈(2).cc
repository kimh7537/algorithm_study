#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b, c;

ll go(ll a, ll b){
//	if(b == 1) return a; 이게 안되는 반레 (4, 1, 3) -> b가 1이라면 %c 연산이 발생하지 않고 바로 a를 반환함
	if(b == 0) return 1;
	ll ret = go(a, b/2); 
	ret = (ret * ret) % c;
	if(b % 2) ret = (ret * a) % c;
	return ret;
}

int main(){
	
	cin >> a >> b >> c;
		
	cout << go(a, b) << "\n";
	
	return 0;
}
