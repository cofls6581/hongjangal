#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; // 부등호 개수
char sign[9];

bool checkSign(vector<int> &perm) {
	for (int i = 0; i < N; i++) {
		if (sign[i] == '<') {
			if (perm[i] > perm[i + 1]) return false;
		}
		if (sign[i] == '>') {
			if (perm[i] < perm[i + 1]) return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> sign[i];
	}

	vector<int> small(N + 1);
	vector<int> big(N + 1);

	for (int i = 0; i <= N; i++) {
		small[i] = i;
		big[i] = 9 - i;
	}

	do {
		if (checkSign(small)) {
			break;
		}
	} while (next_permutation(small.begin(), small.end()));

	do {
		if (checkSign(big)) {
			break;
		}
	} while (prev_permutation(big.begin(), big.end()));

	for (int i = 0; i < N + 1; i++) {
		cout << big[i];
	}
	cout << '\n';
	for (int i = 0; i < N + 1; i++) {
		cout << small[i];
	}
	cout << '\n';

	return 0;
}
