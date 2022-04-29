#include <iostream>
#include <string>

using namespace std;

int N, M;
string arr[20];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int solve(int x1, int y1, int x2, int y2, int cnt) {
	// 실패한 경우1 (버튼을 10번보다 많이 눌러야하는 경우)
	if (cnt == 11) return -1;
	// 성공한 경우 검사(둘 중 하나만 밖으로 떨어지면 성공)
	bool fall1 = false, fall2 = false;
	if (x1 < 0 || x1 >= N || y1 < 0 || y1 >= M) fall1 = true;
	if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= M) fall2 = true;
	// 실패한 경우2 (둘 다 떨어진 경우)
	if (fall1 && fall2) return -1;
	// 성공한 경우
	if (fall1 || fall2) return cnt;
	
	// 다음 호출
	int ans = -1;
	for (int i = 0; i < 4; i++) {
		int nx1 = x1 + dx[i];
		int ny1 = y1 + dy[i];
		int nx2 = x2 + dx[i];
		int ny2 = y2 + dy[i];
		if (nx1 >= 0 && nx1 < N && ny1 >= 0 && ny1 < M && arr[nx1][ny1] == '#') { // 벽 처리
			nx1 = x1;
			ny1 = y1;
		}
		if (nx2 >= 0 && nx2 < N && ny2 >= 0 && ny2 < M && arr[nx2][ny2] == '#') { // 벽 처리
			nx2 = x2;
			ny2 = y2;
		}
		int tmp = solve(nx1, ny1, nx2, ny2, cnt + 1);
		if (tmp == -1) continue;
		if (ans == -1 || tmp < ans) {
			ans = tmp;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'o') {
				if (x1 == -1) { // 첫번째 동전
					x1 = i;
					y1 = j;
				}
				else { // 두번째 동전
					x2 = i;
					y2 = j;
				}
				arr[i][j] = '.';
			}
		}
	}
	cout << solve(x1, y1, x2, y2, 0) << '\n';
	return 0;
}
