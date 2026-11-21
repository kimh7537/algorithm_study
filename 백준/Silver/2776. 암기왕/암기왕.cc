#include<bits/stdc++.h>
using namespace std;

int t, n, m;
long long num;
vector<long long> v;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> t;
    for(int i = 0 ; i < t ; i++){
    	cin >> n;
    	for(int j = 0 ; j < n ; j++){
    		cin >> num;
    		v.push_back(num);
		}
		sort(v.begin(), v.end());
		cin >> m;
		for(int k = 0 ; k < m ; k++){
			cin >> num;

			if (binary_search(v.begin(), v.end(), num) ){ 
			    cout << "1" << "\n";
			} else {
			    cout << "0" << "\n";
			}
		}
    	v.clear();
	}
	
	return 0;
}