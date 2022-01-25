#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define N_MAX 20
int S[N_MAX][N_MAX];
int N;
vector<int> team1;
vector<int> team2;
int team1Sum, team2Sum;
int diff;
int minOfDiff = 1000000;

void recursive(int idx) {
	if (idx == N) {
		if ((team1.size() == N / 2) && (team2.size() == N / 2)) { // team1과 team2가 균등하게 분배되었다면
		team1Sum = 0; team2Sum = 0;

		for (int i = 0; i < N / 2; ++i) {
			for (int j = 0; j < N / 2; ++j) {
				team1Sum += S[team1[i]][team1[j]];
				team2Sum += S[team2[i]][team2[j]];
			}
		}
		diff = abs(team1Sum - team2Sum);
		if (diff < minOfDiff) minOfDiff = diff;
		}
		return;
	}

	team1.push_back(idx);
	recursive(idx + 1);
	team1.pop_back();

	team2.push_back(idx);
	recursive(idx + 1);
	team2.pop_back();
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> S[i][j];
		}
	}
		
	recursive(0);

	cout << minOfDiff;
	return 0;
}
