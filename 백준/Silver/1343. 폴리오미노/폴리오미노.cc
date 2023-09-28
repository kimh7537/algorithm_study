#include <bits/stdc++.h>
using namespace std;
string board;

int main(void) {
  cin >> board;

  string ans = "";
  int i = 0;
  int cnt = 0;
  while(i<board.length()) {

    if (board[i] == '.') {
      i++;
      ans += '.';
      continue;
    }

    for(int j  = i; j< board.length() && board[j] == 'X';j++) {
      cnt++;
    }
    
    if (cnt % 2 != 0) {
      cout << -1;
      return 0 ;
    }

    i+= cnt;


    while(true) {
    if (cnt >= 4) {
      ans += "AAAA";
      cnt-=4;
    } else if (cnt == 2) {
      ans += "BB";
      cnt-=2;
    } else {
      break;
      }
    }
  }

  cout << ans;
} 
 