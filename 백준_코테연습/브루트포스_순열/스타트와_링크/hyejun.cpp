#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vector<vector<int>> a(N, vector<int>(N)); // 2차원 벡터 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	vector<int> players(N, 0); // 각 선수의 팀을 표시하는 벡터
	for (int i = 0; i < N / 2; i++) {
		players[i] = 1;
	}
	sort(players.begin(), players.end());
	int ans = INT_MAX;
	do {
		vector<int> team1;
		vector<int> team2;
		for (int i = 0; i < N; i++) {
			if (players[i] == 0) {
				team1.push_back(i);
			}
			else {
				team2.push_back(i);
			}
		}
		// 능력치 계산
		int tmp1 = 0;
		int tmp2 = 0;
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				if (j == i) continue;
				tmp1 += a[team1[i]][team1[j]];
				tmp2 += a[team2[i]][team2[j]];
			}
		}
		int diff = (tmp1 > tmp2) ? tmp1 - tmp2 : tmp2 - tmp1;
		if (diff < ans) {
			ans = diff;
		}

	} while (next_permutation(players.begin(), players.end()));

	cout << ans << '\n';
	return 0;
}
