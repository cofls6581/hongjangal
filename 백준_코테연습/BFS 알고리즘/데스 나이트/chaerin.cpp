#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int n;
int dx[] = {-2,-2,0,0,2,2};
int dy[] = {-1,1,-2,2,-1,1};
int arr[201][201];
int x1,x2,y1,y2;
queue<pair<int,int>> q;

void bfs(){
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        for (int k=0; k<6; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <=ny && ny < n) {
                if (arr[nx][ny] == -1) {
                    q.push(make_pair(nx,ny));
                    arr[nx][ny] = arr[x][y] + 1;
                }
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin >> n;
    cin>>x1>>y1>>x2>>y2;
    memset(arr,-1,sizeof(arr));
    //로직
    arr[x1][y1]=0; //초기값 세팅
    q.push(make_pair(x1,y1));
    bfs();
    //output
    cout << arr[x2][y2] << '\n';
    return 0;
}
