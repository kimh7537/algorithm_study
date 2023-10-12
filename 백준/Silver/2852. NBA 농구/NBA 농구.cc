#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, tName, min, sec;
	int result1 = 0, result2 = 0, s1 = 0, s2 = 0, res;
	string time;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tName >> time;
		min = stoi(time.substr(0, 2));
		sec = stoi(time.substr(3, 5));

		if (s1 > s2) {
			result1 = result1 + (min * 60) + sec - res;
		}
		else if (s1 < s2) {
			result2 = result2 + (min * 60) + sec - res;
		}
		
		if (tName == 1) s1++;
		else s2++;
		
		res = (min * 60) + sec;
	}

	if (s1 > s2) {
		result1 = result1 + (48 * 60) - res;
	}
	else if (s1 < s2) {
		result2 = result2 + (48 * 60) - res;
	}
	
	printf("%02d:%02d\n", result1 / 60, result1 % 60);
	printf("%02d:%02d\n", result2 / 60, result2 % 60);
	
	return 0;
}