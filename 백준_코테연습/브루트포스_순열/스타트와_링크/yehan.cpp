#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 선언 및 입력
	int n;
	cin >> n;
	vector<vector<int>> score(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> score[i][j];
		}
	}

	vector<int> team(n);
	for (int i = 0; i < n / 2; ++i) team[i] = 1;
	sort(team.begin(), team.end());
	
	// 문제 풀기
	int ans = 9876543210;
	do
	{
		// 팀 나누기
		vector<int> first, second;
		for (int i = 0; i < n; ++i) {
			if (team[i] == 0) first.push_back(i);
			else second.push_back(i);
		}

		// 팀 능력치 구하기
		int one = 0;
		int two = 0;
		for (int i = 0; i < n / 2; ++i) {
			for (int j = 0; j < n / 2; ++j) {
				if (i == j) continue;
				one += score[first[i]][first[j]];
				two += score[second[i]][second[j]];
			}
		}

		// 능력치 차이 구하기
		int diff = one - two;
		if (diff < 0) diff = -diff;
		if (ans > diff) ans = diff;

	} while (next_permutation(team.begin(), team.end()));

	// 출력 및 종료
	cout << ans << '\n';
	return 0;
}
