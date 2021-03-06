#include <iostream>
# define MAX 21
using namespace std;

int N,S;
int arr[MAX] = { 0, };
int ans = 0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	cin >> N >> S;
	for (int i = 0; i < N; i++) 
		cin >> arr[i];

	for (int i = 1; i < (1 << N); i++) {
		int sum = 0;
		for (int j = 0; j < N; ++j) {
			if (i & (1 << j))
				sum += arr[j];
		}
		if (sum == S)
			ans++;
	}

	cout << ans << '\n';
	return 0;
}
