#include <iostream>

using namespace std;

int sum;
bool visited[1501][1501];

void dfs(int a, int b) {
	if (visited[a][b]) return;
	visited[a][b] = true;
	int arr[3] = { a,b,sum - a - b };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i] < arr[j]) {
				int changed[3] = { a,b,sum - a - b };
				changed[i] += arr[i];
				changed[j] -= arr[i];
				dfs(changed[i], changed[j]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	sum = a + b + c;
	if (sum % 3 != 0) {
		cout << 0 << '\n';
		return 0;
	}
	dfs(a, b);
	if (visited[sum / 3][sum / 3]) {
		cout << 1 << '\n';
	}
	else {
		cout << 0 << '\n';
	}
	return 0;
}
