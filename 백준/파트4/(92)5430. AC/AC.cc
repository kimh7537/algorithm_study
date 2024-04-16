#include <bits/stdc++.h>
using namespace std;

int t, n, num, temp;
string s;
char temp1, temp2, c;
deque<int> v;
bool flag= 0, rev=0;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	while(t--){
		cin >> s;
		cin >> n;
		
		cin >> temp1;
		for(int i = 0 ; i < n-1 ; i++){
			cin >> num >> c;
			v.push_back(num);
		}
		if(n >= 1){
			cin >> num;
			v.push_back(num);
		}
		cin >> temp2;
		
		
		for(int i = 0 ; i < s.size() ; i++){
			if(s[i] == 'R'){
				if(rev == 1){
					rev = 0;
				}else if(rev == 0){
					rev = 1;
				}
			}else if(s[i] == 'D'){
				if(v.empty()){
					flag = 1;
					break;
				}
				else if(rev == 1){
					v.pop_back();
				}else if(rev == 0){
					v.pop_front();
				}
			}
		}
		
		
		if(flag){
			cout << "error" << "\n";
		}else{
			cout << temp1;
			if(v.size() > 0){
				if (rev == 0) {
					for(int i = 0 ; i < v.size() - 1 ; i++){
						cout << v[i] << ",";
					}
					cout << v.back();
				}else{
					for(int i = v.size()-1 ; i > 0 ; i--){
						cout << v[i] << ",";
					}
					cout << v.front();
				}
			}
			cout << temp2 << "\n";
			
		}
		
		flag = 0;
		rev = 0;
		v.clear();
	}
	
	
	
	return 0;
}
