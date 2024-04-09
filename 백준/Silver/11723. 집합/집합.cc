#include <bits/stdc++.h>
using namespace std;
long long ret;
int m, num;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> m;

	for(int i = 0 ; i < m ; i++){
		cin >> s;
		if(s != "all" && s != "empty"){
			cin >> num;
		}
		
		if(s == "add"){
			ret |= (1 << num-1);
		}else if(s == "remove"){
			ret &= ~(1 << num-1); 
		}else if(s == "check"){
			if(ret & (1 << num-1)) cout << 1 << "\n";
			else cout << 0 << "\n";
		}else if(s == "toggle"){
			ret ^= (1 << num-1);
		}else if(s == "all"){
			ret = (1 << 20) - 1;
		}else if(s == "empty"){
			ret = 0;
		}
	}
	
	
	return 0;
}