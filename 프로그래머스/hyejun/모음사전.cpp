#include <bits/stdc++.h>
using namespace std;

string s = "AEIOU";
set<string> se;
string res;

void go() {
    if(res.size() > 5) return;
    if(res.size()) {
        se.insert(res);
    }
    
    for(int i=0; i<5; ++i) {
        res += s[i];
        go();
        res.pop_back();
    }
}

int solution(string word) {
    go();
    int ans = 0;
    for(auto i : se) {
        ans++;
        if(i == word) return ans;
    }
    return ans;
}
