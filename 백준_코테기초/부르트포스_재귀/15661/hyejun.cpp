#include <iostream>
#include <vector>
#include <algorithm> // min()
#include <cmath> // abs()
#include <climits> // INT_MAX
#define MAX 20

using namespace std;

int N, S[MAX][MAX], x, team1_sum, team2_sum, result = INT_MAX;
vector<int> team1, team2;

// ��� ���� �ݶ��ϴ� ��� ��츦 �� Ž���ұ�?? N���� ��Ʈ�� �� ����� ������� ���ϴ��� ǥ��!
void solve() {
	for (int i = 0; i < (1 << N); i++) {
		team1.clear(); // ������� �� ������ ������ ������ ����Ҷ����� ó���� ���� �ʱ�ȭ �ؾ���.
		team2.clear();
		for (int j = 0; j < N; j++) { // N���� ��Ʈ�� ����
			if ((i & (1 << j)) == 0) team1.push_back(j); // �ش� ��Ʈ�� 0�̸� team1�� �ְ�,
			else team2.push_back(j); // �ش� ��Ʈ�� 1�̸� team2�� ����.
		}

		if (team1.size() > 0 && team2.size() > 0) { // i�� ��� 1�� ������Ű�ٰ�, �� ���� 1�� �̻� �ִ� ���
			team1_sum = 0;
			team2_sum = 0;
			for (int i = 0; i < team1.size(); i++) { // �� ������ 2�� �����ϴ� ��� ���տ� ���� �ɷ�ġ ���ϱ�.
				for (int j = i + 1; j < team1.size(); j++) {
					team1_sum += S[team1[i]][team1[j]] + S[team1[j]][team1[i]];
				}
			}
			for (int i = 0; i < team2.size(); i++) { // �� ������ 2�� �����ϴ� ��� ���տ� ���� �ɷ�ġ ���ϱ�.
				for (int j = i + 1; j < team2.size(); j++) {
					team2_sum += S[team2[i]][team2[j]] + S[team2[j]][team2[i]];
				}
			}
			result = min(result, abs(team1_sum - team2_sum)); // �� ���� �ɷ�ġ ������ �ּڰ� ����
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