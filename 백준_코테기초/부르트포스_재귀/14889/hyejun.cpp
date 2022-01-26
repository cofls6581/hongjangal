#include <iostream>
#include <vector>
#include <algorithm> // min()
#include <cmath> // abs()
#include <climits> // INT_MAX
#define MAX 20

using namespace std;

int N, x, S[MAX][MAX], result = INT_MAX, team1_sum, team2_sum;
vector<int> team1, team2;

void solve(int player_num) {
	if (player_num == N) {
		if (team1.size() == N / 2 && team2.size() == N / 2) {
			team1_sum = 0;
			team2_sum = 0;
			for (int i = 0; i < N / 2; i++) {
				for (int j = i + 1; j < N / 2; j++) {
					team1_sum += S[team1[i]][team1[j]] + S[team1[j]][team1[i]];
					team2_sum += S[team2[i]][team2[j]] + S[team2[j]][team2[i]];
				}
			}
			result = min(result, abs(team1_sum - team2_sum));
		}
		return;
	}
	//Àç±Í ºÎºÐ
	team1.push_back(player_num);
	solve(player_num + 1);
	team1.pop_back();

	team2.push_back(player_num);
	solve(player_num + 1);
	team2.pop_back();
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
	solve(0);
	cout << result << '\n';
	return 0;
}