#include <bits/stdc++.h>
using namespace std;

int temp, n, d, root;
int child;
vector<int> v[54];

void dfs(int here){
	if(v[here].size() == 0) child++;
	if(v[here].size() == 1 && v[here][0] == d) child++; //-1 0 -> 1번 노드 삭제와 같은 예외 처리 로직
	
	for(int there : v[here]){
		if(there == d) continue;
		dfs(there);
	}
	return;
}
 

int main(){
	cin >> n;
	
	for(int i=0 ; i < n ; i++){
		cin >> temp;
		if(temp == -1){
			root = i;
			continue;
		}
		v[temp].push_back(i);
	}
	
	cin >> d;
	if(root == d){
		cout << "0" << "\n";
		return 0;
	}
	dfs(root);
	cout << child << "\n";
	
	return 0;
}
