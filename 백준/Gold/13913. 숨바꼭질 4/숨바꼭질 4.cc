#include <bits/stdc++.h>
using namespace std;

int n, k;
queue<int> q;
int visited[100004];
int value[100004];
int cnt[1000004];
vector<int> v;

int main(){
	
	cin >> n >> k;
	
	if(n == k){
		cout << "0" << "\n";
		cout << n << "\n";
		return 0;
	}
	
	q.push(n);
	visited[n] = 1;
	cnt[n] = 1;
	while(q.size()){
		int num = q.front();
		q.pop();
		
		for(int next : {num-1, num+1, num*2}){
			if(0 <= next && next <= 100000){
//				if(visited[next]){
//					if(visited[next] == visited[num] + 1){
//						cnt[next] += cnt[num];
//					}
//				}
				if(!visited[next]){
					q.push(next);
					visited[next] = visited[num] + 1;
					value[next] = num;
//					cnt[next] += cnt[num];
				}
			}	
		}
	}
	
	cout << visited[k] - 1 << "\n";
	int temp = value[k];
	v.push_back(k);
	while(true){
		v.push_back(temp);
		if(temp == n){
			reverse(v.begin(), v.end());
			for(int i : v){
				cout << i << " ";
			}
			break;
		}
		int temp1 = value[temp];
		temp = temp1;
	}
	cout << "\n";
	
//	cout << cnt[k] << "\n";
	
	return 0;
}