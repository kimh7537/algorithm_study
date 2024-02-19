#include <bits/stdc++.h>
using namespace std;

int n, m, temp, sum, cnt;
vector<int> v;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 0 ; i < n ; i++){
		cin >> temp;
		v.push_back(temp);
	}
	
	for(int i = 0 ; i < v.size()-1 ; i++){
		for(int j = i + 1 ; j < v.size() ; j++){
			sum = v[i] + v[j];
			if(sum == m){
				cnt++;
			}
		}
	}
	
	cout << cnt << "\n";
	
	return 0;
}
