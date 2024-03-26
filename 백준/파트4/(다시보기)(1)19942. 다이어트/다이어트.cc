#include <bits/stdc++.h>
using namespace std;

int n, ck[5], arr[20][10], res = 987654321;
vector<vector<int>> ret;

bool check(vector<int> c){
	int temp[10] = {0, }, cnt = 0;
	if(c.size()){   // 3 , 0 0 0 0, 0 0 0 0 0, 0 0 0 0 0, 0 0 0 0 0 반례를 통한 수정
		for(int i = 0 ; i < 4 ; i++){
			for(auto it : c){
				temp[i] += arr[it][i];
			}
			if(temp[i] >= ck[i]){
				cnt++;
			}
		}
	}
	if(cnt == 4) return true;
	else return false;
}

void solve(int idx, vector<int> vv){
	if(idx == n){    //idx == n 수정했음
		if(check(vv)){
			int t1 = 0;
			for(auto it : vv){
				t1 += arr[it][4];
			}
			if(t1 < res){
				res = t1;
				ret.clear();
				sort(vv.begin(), vv.end());
				ret.push_back(vv);
			}else if(t1 == res){
				sort(vv.begin(), vv.end());
				ret.push_back(vv);
			}
		}
		return;	
	}

	solve(idx+1, vv);
	vv.push_back(idx+1);
	solve(idx+1, vv);
}

int main(){
	cin >> n;
	
	for(int i = 0 ; i < 4 ; i++){
		cin >> ck[i];
	}
	
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j < 5; j++){
			cin >> arr[i][j];
		}
	}
	vector<int> v;
	solve(0, v);
	
	if(res != 987654321){
		cout << res << "\n";
		sort(ret.begin(), ret.end());
		for(int i = 0 ; i < ret[0].size() ; i++){
			cout << ret[0][i] << " ";
		}
	}else{
		cout << -1 << "\n";
	}
	
	
	return 0;
}
