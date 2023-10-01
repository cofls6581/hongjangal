#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <tuple>
#pragma warning(disable:4996)

using namespace std;

typedef pair<int, int> pp;
const int mx = 19;
int n, m, ans;
int a[mx][mx], visited[mx][mx];
int dy[] = { 0,-1,-1,-1,0,1,1,1 };
int dx[] = { 1,1,0,-1,-1,-1,0,1 };
vector<pp> mv, vita[104]; // 년도별 이동정보, 영양제 위치

bool inRange(int y,int x) {
    return ((y >= 0) && (y < n) && (x >= 0) && (x < n));
}

pp range(int y, int x) {
    int ny, nx;
    if (y < 0) ny = n - y;
    else if (y >= n) ny = y - n;
    if (x < 0) nx = n - x;
    else if (x >= n) nx = x - n;
    return make_pair(ny, nx);
}

pp getNext(int y, int x, int d, int p) {
    int ny = (y + dy[d] * p + n * p) % n;
    int nx = (x + dx[d] * p + n * p) % n;

    return make_pair(ny, nx);
}

void go(int year) {
    int next_year = year + 1;
    int d, p;
    tie(d, p) = mv[year];
    // 1 : 영양제 이동 (반대편과 연결)
    for (pp i : vita[year]) {
        int ny, nx;
        tie(ny, nx) = getNext(i.first, i.second, d, p);
        vita[next_year].push_back(make_pair(ny, nx));
    }
    // 영양제 있는 칸 성장
    for (pp i : vita[next_year]) {
        a[i.first][i.second]++; // 체크
        visited[i.first][i.second] = 1;
    }
    for (pp i : vita[next_year]) {
        int cnt = 0;
        // 2 : 대각선 탐색 -> 높이 1 이상인 칸 개수만큼 성장 (격자 범위 내)
        for (int j = 1; j < 8; j += 2) {
            int ny = i.first + dy[j];
            int nx = i.second + dx[j];
            if (!inRange(ny, nx)) continue;
            if (a[ny][nx] >= 1) cnt++;
        }
        a[i.first][i.second] += cnt;
    }
    // 방금 영양제 투입한 칸을 제외한 칸 중 (높이 >= 2) 인 칸 -> 높이 2 줄이고, 해당 위치에 특수 영양제 두기
    vita[next_year].clear();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i][j]) continue;
            if (a[i][j] < 2) continue;
            a[i][j] -= 2;
            vita[next_year].push_back(make_pair(i, j));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    int d, p;
    for (int i = 0; i < m; ++i) {
        cin >> d >> p;
        mv.push_back(make_pair(d - 1, p));
    }

    // 초기 영양제
    for (int i = n - 2; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            vita[0].push_back(make_pair(i, j));
        }
    }
    
    for (int i = 0; i < m; ++i) { // m년 만큼
        memset(visited, 0, sizeof(visited));
        go(i);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans += a[i][j];
        }
    }
    cout << ans << '\n';

    return 0;
}
