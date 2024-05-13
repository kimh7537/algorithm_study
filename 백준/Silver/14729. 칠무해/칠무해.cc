#include<bits/stdc++.h>
using namespace std;

priority_queue<double, vector<double>, greater<double>> pq;
int n;
double a;


int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		//cout << "cin : " << a << "\n";
		pq.push(a);
	}


	for (int i = 0; i < 7; i++) {
		double a = pq.top();
		printf("%.3lf\n", a);
		pq.pop();
	}
	


	return 0;
}