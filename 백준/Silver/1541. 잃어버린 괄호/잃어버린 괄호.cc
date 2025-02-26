#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> num, v;
vector<char> op;
int temp, rnum, result;

int main(){
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] != '-' && s[i] != '+'){
			v.push_back(s[i] - '0');
		}else{
			op.push_back(s[i]);
			temp = (int)v.size() - 1;
			for(auto it : v){
//				cout << "it : " << it << " temp : "<< temp <<  "\n";
				if(it == 0) {
					temp--;
					continue;
				}
				rnum += (it * (int)pow(10, temp));
//				cout << "rnum : " << rnum << "\n";
				temp--;
			}
			num.push_back(rnum);
			rnum = 0;
			v.clear();
		}
	}
	if(!v.empty()){
		temp = (int)v.size() - 1;
		for(auto it : v){
			if(it == 0) {
				temp--;
				continue;
			}
			rnum += (it * (int)pow(10, temp));
			temp--;
		}
		num.push_back(rnum);
	}
	
//	for(auto it : num) cout << it << " ";
//	cout << "\n";
//	for(auto it : op) cout << it << " ";
//	cout << "\n";
//	
//	result = num[0];
	temp = num[0];
	for(int i = 0 ; i < op.size() ; i++){
		if(op[i] == '-'){
			result += temp;
			temp = 0 - num[i+1];
		}else if(op[i] == '+'){
			if(temp < 0) temp -= num[i+1];
			else temp += num[i+1];
		}
//		cout << "i : " << i << " result : " << result << " temp : " << temp << "\n";
	}
	result += temp;
	
	cout << result << "\n";
	
	return 0;
}