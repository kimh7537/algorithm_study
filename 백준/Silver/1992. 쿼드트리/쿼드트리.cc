#include <bits/stdc++.h>
using namespace std;
int N, arr[68][68];
vector<string> v;
string s;

void dc(int a, int b, int n){
	int n2 = n/2;
	
	vector<pair<int, int>> p;
	p.push_back({a, b});
	p.push_back({a, b+n2});
	p.push_back({a+n2, b});
	p.push_back({a+n2, b+n2});
	
	for(int k = 0 ; k < 4 ; k++){
		int y, x;
		int cnt = 0;
		tie(y, x) = p[k];
		
		for(int i = y; i < y+n2 ; i++){
			for(int j = x ; j < x+n2 ; j++){
				if(arr[i][j] == 1) cnt++;
			}
		}
		
		if(cnt == n2*n2) {
			v.push_back("1");
			continue;
		}
		else if(cnt == 0){
			v.push_back("0");
			continue;
		}
		else{
			v.push_back("(");
			dc(y, x, n2);
		}
	}
	v.push_back(")");
}

int main(){
	cin >> N;
	for(int i = 0 ; i < N ; i++){
		cin >> s;
		for(int j = 0 ; j < N ; j++){
			arr[i][j] = s[j] - '0';
		}
	}
	
	int c= 0;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			if(arr[i][j] == 1) c++;
		}
	}
	
	if(c==N*N) cout << "1";
	else if(c==0) cout << "0";
	else{
		v.push_back("(");
		dc(0, 0, N);
		for(string s : v){
			cout << s;
		}
	}	
	
	
	return 0;
}