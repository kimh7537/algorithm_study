#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums){
    int n = nums.size();
    int picks = n / 2;
    set<int> st(nums.begin(), nums.end());
    int kinds = st.size();

    return min(picks, kinds);
}