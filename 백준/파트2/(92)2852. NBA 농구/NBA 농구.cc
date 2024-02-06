#include <bits/stdc++.h>
using namespace std;

int n, team, ret1, ret2, temp1, temp2;
string s;
map<int, int> mp;

int main(){
	cin >> n;
	mp[1] = 0;
	mp[2] = 0;
	int flag = -1;
	
	for(int i = 0 ; i < n ; i++){
		cin >> team >> s;
		int temp = ((s[0]-'0')*10 + s[1]-'0') * 60 + ((s[3]-'0')*10 + s[4]-'0');
		mp[team]++;
		if(flag == 1) ret1 += (temp - temp1);
		else if(flag == 0) ret2 += (temp - temp2);
		
		if(mp[1] == mp[2]) {
			flag = -1;
			continue;
		} 
		else if(mp[1] > mp[2]) temp1 = temp, flag=1;
		else if(mp[1] < mp[2]) temp2 = temp, flag=0;
	}
	if(flag == 1) ret1 += (48*60 - temp1);
	else if(flag == 0) ret2 += (48*60 - temp2);
	
	
	printf("%02d:%02d", ret1/60, ret1%60);
	cout << "\n";
	printf("%02d:%02d", ret2/60, ret2%60);
	
	return 0;
}
