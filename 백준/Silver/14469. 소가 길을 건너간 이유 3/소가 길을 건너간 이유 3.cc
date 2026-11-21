#include<bits/stdc++.h>
using namespace std;

int n, a, b, result;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 0 ; i < n ; i++){
    	cin >> a >> b;
    	v.push_back({a, b});
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(auto it : v){
		if(result > it.first){
			result += it.second;
		}else if(result <= it.first){
			result = it.first + it.second;
		}
	}
	
	cout << result << "\n";
	
	return 0;
}