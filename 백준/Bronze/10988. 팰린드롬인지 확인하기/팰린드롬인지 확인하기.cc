#include <bits/stdc++.h>
using namespace std;

string s;
bool cmp;

int main(){
	cin >> s;
	
	int len = s.size();
	cmp = true;

	for(int i = 0 ; i < len/2 ; i++){
		if(*(s.begin() + i) != *(s.end() - (i+1))){
			cmp = false;
			break;
		}
	}
	
	cout << cmp;
	
	return 0;
}