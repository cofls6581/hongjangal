#include <bits/stdc++.h>
#define MAX 18
using namespace std;

const int INF=1e9;
int n;
int arr[MAX][MAX];
bool visited[18];
int dp[MAX][1<<MAX]; // 현재 도시, 현재 방문 상태

int tsp(int here, int visited){
    if(visited == (1<<n)-1){
        return arr[here][0]? arr[here][0]:INF; //원점 순회 가능 체크
    }
    int &ret= dp[here][visited];
    if(ret) return ret; //중복 계산 방지

    ret=INF;
    for(int i = 0; i < n; i++){
        if(visited & (1 << i)) continue; //이미 i 방문
        if(arr[here][i] == 0) continue; //방문 불가
        ret = min(ret, tsp(i, visited | (1 << i)) + arr[here][i]);
    }
    return ret;
}

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin>>arr[i][j];
        }
    }

    cout<<tsp(0,1)<<'\n';
    
    return 0;
}
