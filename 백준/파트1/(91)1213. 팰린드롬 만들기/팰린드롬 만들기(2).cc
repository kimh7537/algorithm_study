#include<bits/stdc++.h> 
using namespace std; 
string s, ret; 
int cnt[200], flag; 
char mid;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	for(char a : s)cnt[a]++;
	for(int i = 'Z'; i >= 'A'; i--){  //오름차순 정렬을 위해 Z부터 시작
		if(cnt[i]){
			if(cnt[i] & 1){  //홀수인지 판별, 홀수의 이진수
				mid = char(i);flag++;
				cnt[i]--;
			}
			if(flag == 2)break;
			for(int j = 0; j < cnt[i]; j += 2){
				ret = char(i) + ret;  //ret의 앞에 붙임
				ret += char(i);       //ret의 뒤에 붙임
			}
		}
	}
	if(mid)ret.insert(ret.begin() + ret.size() / 2, mid);
	if(flag == 2)cout << "I'm Sorry Hansoo\n";
	else cout << ret << "\n"; 
}
