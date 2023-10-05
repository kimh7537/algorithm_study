#include <bits/stdc++.h>
using namespace std;

int stu[20];
int main()
{
    
    int T, num, result = 0;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> num;
        result = 0;
        for (int i = 0; i < 20; i++) cin >> stu[i];
        for (int i = 0; i < 20; i++) {
            for (int j = i; j < 20; j++) {
                if (stu[i] > stu[j]) result += 1;
            }
        }
        cout << num << ' ' << result << "\n";
    }

    return 0;
}