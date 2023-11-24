#include <bits/stdc++.h>
using namespace std;

vector<int>v1;
vector<int>v2;

int main(){
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++){
		int num;
		cin >> num;
		v1.push_back(num);
	}
	cin >> m;
	for (int i = 0; i < m; i++){
		int num;
		cin >> num;
	  v2.push_back(num);
	}

	sort(v1.begin(), v1.end());

	for (int i = 0; i < m; i++){
		cout <<
			(upper_bound(v1.begin(), v1.end(), v2[i]) - v1.begin()) -
			(lower_bound(v1.begin(), v1.end(), v2[i]) - v1.begin()) 
			<< ' ';
	}

	return 0;
}