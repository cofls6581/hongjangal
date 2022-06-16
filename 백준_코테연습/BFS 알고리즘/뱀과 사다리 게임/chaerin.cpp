#include <iostream>
#include <queue>
using namespace std;
int n,m;
int dist[101];
int nextLoc[101];
queue<int> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 1; i <= 6; i++) {
			int y = x + i;
			if (y > 100) continue;
			y = nextLoc[y];
			if (dist[y] == -1) {
				dist[y] = dist[x] + 1;
				q.push(y);
			}
		}
	}
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin>>n>>m;
    for(int i=1;i<=100;++i){
        nextLoc[i]=i;
        dist[i] = -1;
    }
    while (n--) {
        int x, y;
        cin >> x >> y;
        nextLoc[x] = y;
    }
    while (m--) {
        int x, y;
        cin >> x >> y;
        nextLoc[x] = y;
    }
    dist[1]=0; //시작점 세팅
    q.push(1);
    bfs();
    cout<<dist[100]<<'\n';
    return 0;
}
