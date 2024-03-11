#include <bits/stdc++.h>
using namespace std;

int n, num, res;
int arr[3];
int visited[64][64][64];
queue<tuple<int, int, int>> q;

int bfs(int a, int b, int c){
	
	q.push(make_tuple(a, b, c));
	visited[a][b][c] = 1;
	
	while(q.size()){
		vector<int> v = {9, 3, 1};
		vector<int> temp;
		int a, b, c;
		
		tie(a, b, c) = q.front();
		q.pop();

//		if(visited[0][0][0]) break; //사용가능(1) 
		
		do{
			int na = max(0, a - v[0]);
			int nb = max(0, b - v[1]);
			int nc = max(0, c - v[2]);
			
			if(visited[na][nb][nc]) continue;  //이거때문에 메모리 초과 발생
			if(na == 0 && nb == 0 && nc == 0) return visited[a][b][c];

			q.push(make_tuple(na, nb, nc));
			visited[na][nb][nc] = visited[a][b][c] + 1;
		
		}while(prev_permutation(v.begin(), v.end()));
		
	}
//	return visited[0][0][0] -1;  //사용가능(1) 
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
	
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> arr[i];
	}
	
	cout << bfs(arr[0], arr[1], arr[2]) << "\n";
	
	return 0;
}
