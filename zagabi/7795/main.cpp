#include<bits/stdc++.h>
using namespace std;

int t, n, m, num, result;
vector<int> a, b;

int main(){
	cin >> t;
	
	for(int i = 0 ; i < t ; i++){
		result = 0;
		a.clear();
		b.clear();
		
		cin >> n >> m;
		
		for(int j = 0 ; j < n ; j++){
			cin >> num;
			a.push_back(num);
		}
		
		for(int k = 0 ; k < m ; k++){
			cin >> num;
			b.push_back(num);
		}
		
		sort(b.begin(), b.end());
		sort(a.begin(), a.end());
		
		for(int it = 0 ; it < a.size() ; it++){
			int temp = lower_bound(b.begin(), b.end(), a[it]) - b.begin();
			//cout <<"temp : " << temp << "\n";
			result += temp;
		}
		
		cout << result << "\n";
		
	}

	
	return 0;
}