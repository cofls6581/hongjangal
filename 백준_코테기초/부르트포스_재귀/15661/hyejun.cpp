#include <iostream>
#include <vector>
#include <algorithm> // min()
#include <cmath> // abs()
#include <climits> // INT_MAX
#define MAX 20

using namespace std;

int N, S[MAX][MAX], x, team1_sum, team2_sum, result = INT_MAX;
vector<int> team1, team2;

// 어떻게 팀을 반띵하는 모든 경우를 다 탐색할까?? N개의 비트로 각 사람이 어느팀에 속하는지 표현!
void solve() {
	for (int i = 0; i < (1 << N); i++) {
		team1.clear(); // 사람들을 두 팀으로 나누는 경우들을 계산할때마다 처음에 팀을 초기화 해야함.
		team2.clear();
		for (int j = 0; j < N; j++) { // N개의 비트에 대해
			if ((i & (1 << j)) == 0) team1.push_back(j); // 해당 비트가 0이면 team1에 넣고,
			else team2.push_back(j); // 해당 비트가 1이면 team2에 넣음.
		}

		if (team1.size() > 0 && team2.size() > 0) { // i를 계속 1씩 증가시키다가, 각 팀에 1명 이상 있는 경우
			team1_sum = 0;
			team2_sum = 0;
			for (int i = 0; i < team1.size(); i++) { // 팀 내에서 2명씩 선택하는 모든 조합에 대해 능력치 더하기.
				for (int j = i + 1; j < team1.size(); j++) {
					team1_sum += S[team1[i]][team1[j]] + S[team1[j]][team1[i]];
				}
			}
			for (int i = 0; i < team2.size(); i++) { // 팀 내에서 2명씩 선택하는 모든 조합에 대해 능력치 더하기.
				for (int j = i + 1; j < team2.size(); j++) {
					team2_sum += S[team2[i]][team2[j]] + S[team2[j]][team2[i]];
				}
			}
			result = min(result, abs(team1_sum - team2_sum)); // 두 팀의 능력치 차이의 최솟값 갱신
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x;
			S[i][j] = x;
		}
	}
	solve();
	cout << result << '\n';
	return 0;
}