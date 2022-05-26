#include <iostream>
#include <vector>
#define LIMIT 5

using namespace std;

vector<int> makeDir(int k) { // 2진수를 4진수로 만들어서 방법의 수 만드는 함수.
	vector<int> dir(LIMIT);
	for (int i = 0; i < LIMIT; i++) {
		dir[i] = (k & 3);
		k >>= 2;
	}
	return dir;
}

int checkMax(vector<vector<int>> &a, vector<int> &dirs) { // 방법대로 블록 이동 후 가장 큰 블록값 리턴.
	int n = a.size();
	vector<vector<pair<int, bool>>> d(n, vector < pair<int, bool>>(n)); // pair<블록, 이번 이동에서 합쳐졌는지 여부>
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j].first = a[i][j]; // 이동할 임시 배열 만들기.
		}
	}

	// 0:아래 1:위 2:왼쪽 3:오른쪽 방향대로 이동하기.
	for (int dir : dirs) {
		bool change = false; // 블록에 변화가 있었는지 나타내는 변수.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d[i][j].second = false; // 이번 이동에서 합쳐졌는지 여부 초기화.
			}
		}

		// 이동하기
		while (1) {
			change = false;
			if (dir == 0) { // 아래
				for (int i = n - 2; i >= 0; i--) { // 순서 중요! 0부터 시작하면 안됨!
					for (int j = 0; j < n; j++) {
						if (d[i][j].first == 0) continue; // 해당 칸에 수가 없는 경우
						// 해당 칸에 수가 있다면
						if (d[i + 1][j].first == 0) { // 아래칸에 수가 없다면 이동하기.
							d[i + 1][j].first = d[i][j].first;
							d[i + 1][j].second = d[i][j].second;
							d[i][j].first = 0;
							change = true;
						}
						else if (d[i + 1][j].first == d[i][j].first) { // 아래칸의 수가 현재칸의 수와 같아서 합쳐야하는 경우.
							if (d[i + 1][j].second == false && d[i][j].second == false) {
								d[i + 1][j].first *= 2;
								d[i + 1][j].second = true;
								d[i][j].first = 0;
								change = true;
							}
						}
						// 아래칸에 같지않은 수가 있다면 이동할수없음 = 아무일도 안일어남.
					}
				}
			}
			else if (dir == 1) { // 위
				for (int i = 1; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (d[i][j].first == 0) continue;
						if (d[i - 1][j].first == 0) { // 위칸에 수가 없다면 이동하기.
							d[i - 1][j].first = d[i][j].first;
							d[i - 1][j].second = d[i][j].second;
							d[i][j].first = 0;
							change = true;
						}
						else if (d[i - 1][j].first == d[i][j].first) { // 위칸의 수가 현재칸의 수와 같아서 합쳐야하는 경우.
							if (d[i - 1][j].second == false && d[i][j].second == false) {
								d[i - 1][j].first *= 2;
								d[i - 1][j].second = true;
								d[i][j].first = 0;
								change = true;
							}
						}
					}
				}
			}
			else if (dir == 2) { // 왼쪽
				for (int j = 1; j < n; j++) {
					for (int i = 0; i < n; i++) {
						if (d[i][j].first == 0) continue;
						if (d[i][j - 1].first == 0) { // 왼쪽칸에 수가 없다면 이동하기.
							d[i][j - 1].first = d[i][j].first;
							d[i][j - 1].second = d[i][j].second;
							d[i][j].first = 0;
							change = true;
						}
						else if (d[i][j - 1].first == d[i][j].first) { // 왼쪽칸의 수가 현재칸의 수와 같아서 합쳐야하는 경우.
							if (d[i][j - 1].second == false && d[i][j].second == false) {
								d[i][j - 1].first *= 2;
								d[i][j - 1].second = true;
								d[i][j].first = 0;
								change = true;
							}
						}
					}
				}
			}
			else if (dir == 3) { // 오른쪽
				for (int j = n - 2; j >= 0; j--) {
					for (int i = 0; i < n; i++) {
						if (d[i][j].first == 0) continue;
						if (d[i][j + 1].first == 0) { // 오른쪽칸에 수가 없다면 이동하기.
							d[i][j + 1].first = d[i][j].first;
							d[i][j + 1].second = d[i][j].second;
							d[i][j].first = 0;
							change = true;
						}
						else if (d[i][j + 1].first == d[i][j].first) { // 오른쪽칸의 수가 현재칸의 수와 같아서 합쳐야하는 경우.
							if (d[i][j + 1].second == false && d[i][j].second == false) {
								d[i][j + 1].first *= 2;
								d[i][j + 1].second = true;
								d[i][j].first = 0;
								change = true;
							}
						}
					}
				}
			}

			if (change == false) break; // 더 이상 블록에 변화가 없으면(이동할 수 없으면) 멈추기
		}
	}
	// 가장 큰 블록값 찾기
	int maxBlock = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (maxBlock < d[i][j].first) {
				maxBlock = d[i][j].first;
			}
		}
	}
	return maxBlock;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int ans = 0;
	// 방법의 수 다 만들기
	for (int i = 0; i < (1 << (LIMIT * 2)); i++) {
		vector<int> dir = makeDir(i);
		// 방법대로 블록 이동하기
		int cur = checkMax(a, dir);
		if (ans < cur) ans = cur;
	}
	cout << ans << '\n';
	return 0;
}
