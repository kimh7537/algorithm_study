#include<bits/stdc++.h>
using namespace std;

int n, res;

int main(){
	
	cin >> n;
	
	int temp = 1000 - n;
	
	while(temp > 0){
		if(temp >= 500) {
			res += (temp / 500);
			temp %= 500;
		}else if (temp >= 100 && temp < 500){
			res += (temp / 100);
			temp %=100;
		}else if (50 <= temp && temp < 100){
			res += (temp / 50);
			temp %=50;
		}else if (10 <= temp && temp < 50){
			res += (temp / 10);
			temp %=10;
		}else if (5 <= temp && temp < 10){
			res += (temp / 5);
			temp %=5;
		}else if (1 <= temp && temp < 5){
			res += (temp / 1);
			temp %=1;
		}
	}
	
	cout << res << "\n";
	
	return 0;
}