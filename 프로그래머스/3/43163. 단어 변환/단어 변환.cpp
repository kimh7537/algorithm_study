#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;

void changeToMap(vector<string> words){
    for(string s : words){
        mp.insert({s, 0});
    }
}

bool compareTwo(string temp, string s){
    int cnt = 0;
    for(int i = 0 ; i < temp.size(); i++){
        if(temp[i] != s[i]) cnt++;
    }
    if(cnt == 1) return true;
    else return false;
}

void bfs(string begin, vector<string> words){
    queue<string> q;
    q.push(begin);
    while(q.size()){
        string temp = q.front();
        q.pop();
        
        for(string s : words){
            if(mp[s] != 0) continue;
            if(!compareTwo(temp, s)) continue;    
            q.push(s);
            mp[s] = mp[temp] + 1;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    if(find(words.begin(), words.end(), target) == words.end()){
        return answer;
    }
    
    changeToMap(words);
    
    bfs(begin, words);
    
    return mp[target];
}