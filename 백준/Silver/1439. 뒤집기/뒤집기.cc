#include<iostream>
using namespace std;

string s;
char temp;
int ret1, ret2;

int main(){

    cin >> s;
    temp = s[0];
    for(int i = 1 ; i < s.length() ; i++){
        if(temp != s[i]){
            if (temp == '0') ret1++;
            else ret2++;
            temp = s[i];
        }
    }
    if (temp == '0') ret1++;
    else ret2++;
    cout << min(ret1, ret2) << "\n";

    return 0;
}