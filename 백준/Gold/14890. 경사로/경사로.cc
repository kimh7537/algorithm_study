#include <bits/stdc++.h>
using namespace std;

int cnt, arr[104][104], n, l, visited[104];

void check1(int t){
	memset(visited, 0 , sizeof(visited));
	int temp = arr[t][0];
	for(int i = 1 ; i < n ; i++){
		if(arr[t][i] != temp){
			int dif = arr[t][i] - temp;
			if(abs(dif) != 1) return;
			
			if(dif == 1){
				for(int j = 1 ; j <= l ; j++){
					if(i - j < 0) return;
					if(visited[i - j]) return;
					if(arr[t][i] - arr[t][i-j] != dif) return;
					else visited[i-j] = 1;
				}
				temp = arr[t][i];
			}
			else if(dif == -1){
				for(int j = 0 ; j < l ; j++){
					if(i + j >= n) return;
					if(visited[i+j]) return;
					if(arr[t][i+j] - temp != dif) return;
					else visited[i+j] = 1;
				}
				temp = arr[t][i+l-1];
				i = i + l - 1;
			}
		}
	}
	cnt++;
}

void check2(int t){
	memset(visited, 0 , sizeof(visited));
	int temp = arr[0][t];
	for(int i = 1 ; i < n ; i++){
		if(arr[i][t] != temp){
			int dif = arr[i][t] - temp;
			if(abs(dif) != 1) return;
			
			if(dif == 1){
				for(int j = 1 ; j <= l ; j++){
					if(i - j < 0) return;
					if(visited[i - j]) return;
					if(arr[i][t] - arr[i-j][t] != dif) return;
					else visited[i-j] = 1;
				}
				temp = arr[i][t];
			}
			else if(dif == -1){
				for(int j = 0 ; j < l ; j++){
					if(i + j >= n) return;
					if(visited[i+j]) return;
					if(arr[i+j][t] - temp != dif) return;
					else visited[i+j] = 1;
				}
				temp = arr[i+l-1][t];
				i = i + l - 1;
			}
		}
	}
	cnt++;
}



int main(){
	
	cin >> n >> l;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> arr[i][j];
		}
	}
	
	for(int i = 0 ; i < n ; i++){
		check1(i);
//		cout << i << " " << cnt << "\n";
	}
	for(int i = 0 ; i < n ; i++){
		check2(i);
	}
	
	cout << cnt << "\n";
	
	return 0;
}