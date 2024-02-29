#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    long long cnt = 1;
    int ret = 1;
    
    while(cin >> n){
        cnt = 1;
        ret = 1;
        
        while(true){
            if(cnt % n == 0){
            	cout << ret << "\n";
                break;
            }
            else {
            	cnt = ((cnt * 10)%n + 1%n) % n;
            	ret++;
			}
		}
    }
    return 0;
}
