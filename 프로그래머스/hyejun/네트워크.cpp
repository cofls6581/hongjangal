#include <bits/stdc++.h>

using namespace std;
int visited[204];

void dfs(int x, vector<vector<int>> &computers, int n) {
    visited[x] = 1;
    for(int i=0;i<n;++i) {
        if(visited[i] || computers[x][i]==0) continue;
        dfs(i, computers, n);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0;i<n;++i) {
        if(visited[i]) continue;
        dfs(i, computers, n);
        answer++;
    }
    
    return answer;
}
