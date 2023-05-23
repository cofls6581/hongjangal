#include <iostream>
#include <vector>
#include <cstring>

#define MAX 55
using namespace std;

int N, M, ans;
int water[MAX][MAX];
bool cloudExists[MAX][MAX];
vector<pair<int, int>> cloud;
vector<pair<int, int>> cmd;

int dx[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

void init() {
    cloud.push_back(make_pair(N - 2, 0));
    cloud.push_back(make_pair(N - 2, 1));
    cloud.push_back(make_pair(N - 1, 0));
    cloud.push_back(make_pair(N - 1, 1));
    cloudExists[N - 2][0] = true;
    cloudExists[N - 2][1] = true;
    cloudExists[N - 1][0] = true;
    cloudExists[N - 1][1] = true;
}

int rangeControl(int x) {
    if (x < 0) return N - 1;
    if (x >= N) return 0;
    return x;
}

void moveCloud(int idx) {
    int dir = cmd[idx].first;
    int cnt = cmd[idx].second;
    memset(cloudExists, false, sizeof(cloudExists));
    for (int i = 0; i < cloud.size(); i++) {
        int x = cloud[i].first;
        int y = cloud[i].second;
        int nx = x, ny = y;
        for (int j = 0; j < cnt; j++) {
            nx += dx[dir];
            ny += dy[dir];
            nx = rangeControl(nx);
            ny = rangeControl(ny);
        }
        cloud[i].first = nx;
        cloud[i].second = ny;
    }
    for (int i = 0; i < cloud.size(); i++) {
        int x = cloud[i].first;
        int y = cloud[i].second;
        cloudExists[x][y] = true;
    }
}

void rain() {
    for (int i = 0; i < cloud.size(); i++) {
        int x = cloud[i].first;
        int y = cloud[i].second;
        water[x][y]++;
    }
}

void waterBug() { // 물복사버그
    for (int i = 0; i < cloud.size(); i++) {
        int x = cloud[i].first;
        int y = cloud[i].second;
        int cnt = 0;
        // 대각선 방향으로 거리가 1인 칸에 물이 있는 바구니의 수만큼 증가
        for (int j = 2; j <= 8; j += 2) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (water[nx][ny] >= 1) cnt++;
        }
        water[x][y] += cnt;
    }
}

void removeCloud() {
    cloud.clear();
}

void createCloud() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // 방금 구름이 사라진 칸이 아니어야 함
            if (cloudExists[i][j] == true) continue;
            if (water[i][j] < 2) continue;
            water[i][j] -= 2;
            cloud.push_back(make_pair(i, j));
        }
    }
    // 좌표에서도 이전 구름 삭제
    memset(cloudExists, false, sizeof(cloudExists));
    // 구름 생성
    for (int i = 0; i < cloud.size(); i++) {
        int x = cloud[i].first;
        int y = cloud[i].second;
        cloudExists[x][y] = true;
    }
}

void simulate() {
    init();
    for (int i = 0; i < M; i++) {
        moveCloud(i);
        rain();
        waterBug();
        removeCloud();
        createCloud();
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> water[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        int d, s; 
        cin >> d >> s;
        cmd.push_back(make_pair(d, s));
    }

    simulate();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ans += water[i][j];
        }
    }
    cout << ans << '\n';

    return 0;
}
