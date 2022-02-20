#include <iostream>
#include <algorithm>
#define MAX 501

using namespace std;

int n, d[MAX][MAX], arr[MAX][MAX], answer;

void dp() {
	d[1][1] = arr[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) { // 삼각형에서 제일 왼쪽 수
				d[i][j] = d[i - 1][j] + arr[i][j];
			}
			else if (j == i) { // 삼각형에서 제일 오른쪽 수
				d[i][j] = d[i - 1][j - 1] + arr[i][j];
			}
			else { // 삼각형에서 가운데 수들
				d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + arr[i][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		answer = max(answer, d[n][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	dp();
	cout << answer << '\n';
	return 0;
}
