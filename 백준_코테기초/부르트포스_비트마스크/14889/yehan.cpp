#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int S[20][20];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	vector<int> team1;
	vector<int> team2;
	int team1Sum, team2Sum;
	int diff;
	int minOfDiff = 1000000;

	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> S[i][j];

	for (int i = 0; i < (1 << N); ++i) {
		// ���� �ʱ�ȭ
		team1.clear(); team2.clear();
		team1Sum = 0; team2Sum = 0;

		// �� ������
		for (int j = 0; j < N; ++j) {
			if (i & (1 << j)) team1.push_back(j);
			else team2.push_back(j);
		}

		// ������ �������� ���������� �ʾҴٸ� �Ѿ��
		if (team1.size() != N / 2) {
			continue;
		}

		// �� ���� ����, ���� �� ����ϱ�
		for (int a = 0; a < N / 2; ++a)
		{
			for (int b = 0; b < N / 2; ++b)
			{
				team1Sum += S[team1[a]][team1[b]];
				team2Sum += S[team2[a]][team2[b]];
			}
		}
		diff = abs(team1Sum - team2Sum);

		if (diff < minOfDiff) minOfDiff = diff;
	}
	cout << minOfDiff;
	return 0;
}