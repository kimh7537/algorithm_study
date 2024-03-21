#include <bits/stdc++.h>
using namespace std;

char arr[13];
int visited[13], k, ret;
vector<int> v;

bool oper(int idx, int num){
	if(idx == 0) return true;
	if(arr[idx-1] == '<' && v[idx-1] < num){
		return true;
	}else if(arr[idx-1] == '>' && v[idx-1] > num){
		return true;
	}
	return false;
}

void go(int idx, int num){
	
	if(idx == k+1){
		ret = 1;
		return;
	}
	
	for(int i = 0 ; i < 10 ; i++){
		if(visited[i]) continue;
		if(oper(idx, i)){
			visited[i] = 1;
			v.push_back(i);
			go(idx + 1, i);
			if(ret== 1) return;
			visited[i] = 0;
			v.pop_back();
		}
	}
}

void go2(int idx, int num){
	if(idx == k+1){
		ret = 1;
		return;
	}
	for(int i = 9 ; i >= 0 ; i--){
		if(visited[i]) continue;
		if(oper(idx, i)){
			visited[i] = 1;
			v.push_back(i);
			go2(idx + 1, i);
			if(ret== 1) return;
			visited[i] = 0;
			v.pop_back();
		}
	}
}

int main(){
	cin >> k;
	for(int i=0 ; i < k ; i++){
		cin >> arr[i];
	}
	
	go2(0, 0);
	for(auto it : v){
		cout << it;
	}
	cout << "\n";
	
	v.clear();
	memset(visited, 0 , sizeof(visited));
	ret = 0;
	go(0, 0);
	for(auto it : v){
		cout << it;
	}
	
	return 0;
}