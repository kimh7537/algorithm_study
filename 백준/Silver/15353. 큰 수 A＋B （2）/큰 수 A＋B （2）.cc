#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int temp, i1, i2;
int num, dif;
vector<int> v;
//a가 더 작은 애 
void solve(string a, string b){
	int temp1 = b.size();
	int temp2 = a.size();
	dif = temp1 - temp2;
	
	while(temp2--){
		i1 = a[temp2] - '0';
		i2 = b[temp2+dif] - '0';
		temp = i1 + i2 + num;
		if(temp >= 10){
			num = temp / 10;
			temp = temp - 10;
		}else{
			num = 0;
		}
		v.push_back(temp);
	}
	for(int i = dif-1 ; i>=0 ; i--){
		temp = b[i] - '0' + num;

		if(temp >= 10){
			num = temp / 10;
			temp = temp - 10;
		}else{
			num = 0;
		}
		v.push_back(temp);
	}
	if(num > 0){
		v.push_back(num);
	}
	return;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s1 >> s2;

	
	if(s1.size() > s2.size()){
		solve(s2, s1);
	}else if(s1.size() <= s2.size()){
		solve(s1, s2);
	}
	
	for(int i = v.size()-1 ; i >= 0 ; i--){
		cout << v[i];
	}
	
	return 0;
}