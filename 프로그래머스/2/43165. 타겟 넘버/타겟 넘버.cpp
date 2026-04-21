#include <bits/stdc++.h>

using namespace std;

vector<int> nums;
int n, res, target;

void print(vector<int> v){
    for(auto it : v){
        cout << it << " ";
    }
    cout << "\n";
}

void makeTarget(vector<int> v, int idx){
    if(idx == n){
        int num = accumulate(v.begin(), v.end(), 0);
        if(num == target){
            res += 1;
        }
        return;
    }
    
    v.push_back(nums[idx]);
    // print(v);
    int prev = idx + 1;
    makeTarget(v, prev);
    v.pop_back();

    // cout << "branch : " << '\n';
    // cout << "numx[idx] : " << nums[idx] << "\n";
    // cout << "-nums[idx] : " << -nums[idx] << "\n";
    v.push_back(-nums[idx]);
    // print(v);
    makeTarget(v, prev);
    v.pop_back();
}

int solution(vector<int> numbers1, int t) {
    
    nums = numbers1;
    n = numbers1.size();
    target = t;
    
    vector<int> v;
    v.push_back(nums[0]);
    // print(v);
    makeTarget(v, 1);
    v.pop_back();
    
    v.push_back(-nums[0]);
    // print(v);
    makeTarget(v, 1);
    v.pop_back();
    
    return res;
}