#include <bits/stdc++.h>
#define MAX 62
using namespace std;

int n;
int scv[3];
int attack[]={9,3,1};
int visited[MAX][MAX][MAX];

struct health{
    int a,b,c;
};

int func(int a, int b, int c){
    queue <health> q;
    visited[a][b][c]=0; //마지막에 1 감소 필요
    q.push({a,b,c});

    while(q.size()){
        int a = q.front().a; 
        int b = q.front().b; 
        int c = q.front().c; 
        q.pop();
        if(visited[0][0][0]) break; //정답 케이스
        do{
            int na=max(0,a-attack[0]);
            int nb=max(0,b-attack[1]);
            int nc=max(0,c-attack[2]);
            if(visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[a][b][c] + 1;  
            q.push({na, nb, nc}); 
        }while(prev_permutation(attack,attack+3));
    }
    return visited[0][0][0];
}

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n;
    for(int i=0; i<n; ++i){
        cin>>scv[i];
    }
    cout<<func(scv[0],scv[1],scv[2])<<'\n';
    return 0;
}
