#include<iostream>
using namespace std;

int n, arr[1000004], ret1 = 987654321, ret2 = -1000004;

int main() {
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
        ret1 = min(ret1, arr[i]);
        ret2 = max(ret2, arr[i]);
    }

    cout << ret1 << " " << ret2 << "\n";

    return 0;
}
