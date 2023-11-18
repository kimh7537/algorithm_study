#include <bits/stdc++.h>
using namespace std;
 
int a1[4]={1,-1,0,0};
int b1[4]={0,0,1,-1};

int M,N,K;

int arr[51][51];
bool visited[51][51];
 
void dfs(int a, int b){  //a세로, b가로 
	visited[a][b] = true;

    for(int i = 0 ; i < 4 ; i++){
    	int res1 = a + a1[i]; //세로 
    	int res2 = b + b1[i]; //가로 
    	
        if(res2 < 0 || res2 >= M || res1 < 0 || res1 >= N) 
            continue;
  		
  		if(arr[res1][res2] == 1){
  			if(!visited[res1][res2]){
  				dfs(res1, res2);
			}
		}
    }
}
 
int main(){
    int T;
    cin >> T;
    
    while(T--){
    	cin >> M >> N >> K;
    	int count = 0;
    	for(int i = 0 ; i < K ; i++){
    		int X, Y;
    		cin >> X >> Y;
    		arr[Y][X] = 1;
		}
    	
    	for(int i = 0 ; i < N ; i++){
    		for(int j = 0 ; j < M ; j++){
    			if(arr[i][j] == 1){
    				if(!visited[i][j]){
    					count++;
    					dfs(i, j);
					}
				}
			}
		}
		cout << count << "\n";
		memset(visited, false, sizeof(visited));
		memset(arr, 0 , sizeof(arr));
    	
	}
    
    return 0;
}
