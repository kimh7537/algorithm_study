#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> chick, home;
vector<vector<int>> res;
int arr[54][54];
int n, m;
int ret = 987654321;
int ret1 = 987654321;

void combi(int start, vector<int> v){
	if(v.size() == m){
		res.push_back(v);
		return;
	}
	for(int i=start+1 ; i<chick.size() ; i++){
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
}

int calculate(){
	
	int result = 0;
	int con1 = 987654321;
	int con2 = 0;
	for(vector<int> v : res){
		for(auto it : home){ 
			for(int i : v){ 
				result = abs(it.first-chick[i].first) + abs(it.second - chick[i].second);
				con1 = min(con1, result);
			}
			con2 += con1;
			con1 = 987654321;
		}
		ret = min(ret, con2);
		con2 = 0;
		
	}
	return ret;
}

int main(){
	cin >> n >> m;
	for(int i=1 ; i<=n ; i++){
		for(int j=1; j<=n ; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 2){
				chick.push_back({i, j});
			}
			if(arr[i][j] == 1){
				home.push_back({i, j});
			}
		}
	}
	
//	for(int i=1 ; i<=m ; i++){   //최대 m으로 가정하고 푼 코드도 가능
//		vector<int> v;
//		combi(-1, v, i);
//		ret1 = min(ret1, calculate());
//		res.clear();
//	}
//	cout << ret1 << "\n";
	
	vector<int> v;
	combi(-1, v);	
	cout << calculate() << "\n";
	
	return 0;
}
