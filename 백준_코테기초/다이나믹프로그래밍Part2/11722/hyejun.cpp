#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int N, A[MAX], d[MAX], answer;

void dp() {
	int maxD = 0;
	for (int i = 1; i <= N; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (A[i] < A[j] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
			}
		}
		maxD = max(maxD, d[i]);
	}
	answer = maxD;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	dp();
	cout << answer << '\n';
	return 0;
}
