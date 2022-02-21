#include <iostream>
#include <algorithm>

#define MAX 102
using namespace std;

int N,M;
int answer;
int arr[MAX][MAX] = {0,};
int partSum = 0;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> arr[i][j];
		}
	}
	answer += 2*N * M;

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			for (int k = 0; k < 4; k++) {
				int nr = r + dr[k];
				int nc = c + dc[k];
				if (arr[r][c] >= arr[nr][nc]) {		
					answer += arr[r][c] - arr[nr][nc];
				}
			}
		}
	}

	cout << answer << '\n';
	return 0;
}
