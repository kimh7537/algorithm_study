#include <bits/stdc++.h>
using namespace std;
#define prev aaa
#define next aaaa
const int max_n = 200004;   //목표지점 9만/시작 지점 6만 -> 12만으로 순간이동하고 가는 경우가 더 빠를 수도 있기 때문에 20000으로 해둠
int visited[max_n], prev[max_n], n, k, ret, here, cnt, next;   
vector<int> v; 
queue<int> q;  

int main() { 
    cin >> n >> k; 
    visited[n] = 1; 
    q.push(n);  
    while(q.size()){
        here = q.front();  
        q.pop();
        if(here == k){
            ret = visited[k]; 
            break;
        }
	for(int next : {here + 1, here - 1, here * 2}){
            if(next >= max_n || next < 0 || visited[next]) continue;  
            visited[next] = visited[here] + 1; 
            prev[next] = here;
            q.push(next); 
	} 
    }   
    for(int i = k; i != n; i = prev[i]){
        v.push_back(i);
    }
    v.push_back(n);
    cout << ret - 1<< '\n'; 
    reverse(v.begin(), v.end());
  
    for(int i : v) cout << i << ' '; 
    return 0;
}
