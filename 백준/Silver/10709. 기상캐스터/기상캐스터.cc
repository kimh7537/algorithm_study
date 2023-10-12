#include <bits/stdc++.h>
using namespace std;
char c[101][101];
int arr[101][101];

int main() {
    int h, w;
    cin >> h >> w;
    
    memset(arr, -1, sizeof(arr));
    
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++){
            cin >> c[i][j];
        }
    }
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++){
            if (c[i][j] == 'c'){
                arr[i][j] = 0;
            }
            else if (arr[i][j - 1] >= 0){
                arr[i][j] = arr[i][j - 1] + 1;
            }
        }
    }
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}
