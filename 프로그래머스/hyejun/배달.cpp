#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9, mx = 54;
int ans, dist[mx];
struct edge {
    int end, cost;
    
    bool operator<(const edge &b) const {
        if(cost != b.cost) return cost > b.cost;
        else return end < b.end;
    }
};
vector<vector<edge>> adj;

void dijk(int N) {
    fill(dist, dist+N+1, INF); // 초기화 크기 주의 (N 만큼만 초기화하면 안됨)
    
    priority_queue<edge> pq;
    pq.push({1, 0});
    dist[1] = 0;
    
    while(!pq.empty()) {
        edge top = pq.top(); pq.pop();
        int nowEnd = top.end;
        int nowCost = top.cost;
        if(dist[nowEnd] < nowCost) continue;
        int len = adj[nowEnd].size();
        for(int i=0; i<len; ++i) {
            edge next = adj[nowEnd][i];
            if(dist[next.end] > dist[nowEnd] + next.cost) {
                dist[next.end] = dist[nowEnd] + next.cost;
                pq.push({next.end, dist[next.end]});
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    adj.resize(N + 1); // 꼭 하기!! 안하면 seg fault
    int rLen = road.size();
    for(int i=0; i<rLen; ++i) {
        int a = road[i][0]; int b = road[i][1]; int w = road[i][2];
        adj[a].push_back({b, w}); // 무방향 그래프 -> 양쪽 다 삽입
        adj[b].push_back({a, w});
    }
    dijk(N);
    for(int i=1; i<=N; ++i) {
        if(dist[i] <= K) ans++;
    }
    return ans;
}
