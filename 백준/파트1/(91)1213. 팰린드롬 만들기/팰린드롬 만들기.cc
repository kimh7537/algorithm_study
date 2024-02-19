#include <bits/stdc++.h>
using namespace std;

string s;
int arr[30], cnt, temp;
vector<char> v;
stack<char> stk;

int main(){
	
	cin >> s;
	for(int i=0 ; i < s.size() ; i++){
		arr[s[i] - 'A']++;
	}
	
	if(s.size() % 2 == 0){
		for(int i=0 ; i < 26 ; i++){
			if(arr[i] % 2 == 1){
				cout << "I'm Sorry Hansoo" << "\n";
				return 0;
			}
			for(int j=0 ; j < arr[i]/2 ; j++){
				v.push_back(i + 'A');
				stk.push(i + 'A');
			}
		}
	}
	else if(s.size() % 2 == 1){
		for(int i = 0 ; i < 26 ; i++){
			if(arr[i] % 2 == 1){
				if(cnt > 1){
					cout << "I'm Sorry Hansoo" << "\n";
					return 0;
				}
				cnt++;
				temp = i;
			}
			for(int j=0 ; j < arr[i]/2 ; j++){
				v.push_back(i + 'A');
				stk.push(i + 'A');
			}
		}
	}
	
	for(char c : v){
		cout << c;
	}
	if(cnt == 1) cout << char(temp+'A');
	while(stk.size()){
		cout << stk.top();
		stk.pop();
	}
	
	return 0;
}
