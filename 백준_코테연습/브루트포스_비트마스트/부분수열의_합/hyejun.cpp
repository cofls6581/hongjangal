#include <iostream>
#include <vector>
#define MAX (20*100000+1)
using namespace std;

bool check[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vector<int> s(N);
	for (int i = 0; i < N; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < (1 << N); i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			if ((i & (1 << j)) != 0) {
				sum += s[N - 1 - j];
			}
		}
		check[sum] = true;
	}
	for (int i = 1;; i++) {
		if (check[i] == false) {
			cout << i << '\n';
			break;
		}
	}
	return 0;
}
