#include <iostream>
using namespace std;

int check[1501][1501];
int sum;

void dfs(int x, int y) {
	if (check[x][y]) return;

	check[x][y] = true;
	int a[3] = { x, y, sum - x - y };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[i] < a[j]) {
				int b[3] = { x, y, sum - x - y };
				b[i] += a[i];
				b[j] -= a[i];
				dfs(b[0], b[1]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 선언 및 초기화
	int x, y, z;
	cin >> x >> y >> z;
	sum = x + y + z; // 전체 돌의 개수는 변하지 않음

	// 문제풀기 1) 돌의 개수를 같게 만들 수 없는 경우
	if (sum % 3 != 0) {
		cout << 0 << '\n';
		return 0;
	}

	// 문제풀기 2) dfs
	dfs(x, y);

	if (check[sum / 3][sum / 3]) cout << 1 << '\n';
	else cout << 0 << '\n';

	return 0;
}
