#include <iostream>
#include <queue>
using namespace std;

int f,s,g,u,d;
queue<int> q;
int dist[1000001];
bool check[1000001];

void bfs(){
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now + u <= f && check[now+u] == false) {
            dist[now+u] = dist[now] + 1;
            check[now+u] = true;
            q.push(now+u);
        }
        if (now - d >= 1 && check[now-d] == false) {
            dist[now-d] = dist[now] + 1;
            check[now-d] = true;
            q.push(now-d);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin >> f >> s >> g >> u >> d;
    
    //로직
    q.push(s);
    check[s] = true;
    bfs();
    //output
    if (check[g]) {
        cout << dist[g] << '\n';
    } else {
        cout << "use the stairs\n";
    }
    return 0;
}
