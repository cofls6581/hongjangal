#include <iostream>
#include<vector>
#include<algorithm>
# define MAX 21
using namespace std;

int N,ans=99999999;
int arr[MAX][MAX];
int visit[MAX];
int ss = 0;
int ls = 0;

void team(int idx, int count) {
	vector <int> start, link;
	ss = 0; ls = 0;
	if (count == N / 2) {
		for (int i = 0; i < N; ++i) {
			if (visit[i])
				start.push_back(i);
			else
				link.push_back(i);
		}

		for (int i = 0; i < (N / 2); ++i) {
			for (int j = i + 1; j < (N / 2); j++) {
				ss += (arr[start[i]][start[j]] + arr[start[j]][start[i]]);
				ls += (arr[link[i]][link[j]] + arr[link[j]][link[i]]);
			}
		}
		ans = min(ans, abs(ss - ls));
		return;
	}
	for (int i = idx; i < N; ++i) {
		if (visit[i])
			continue;
		else {
			visit[i] = 1;
			team(i + 1, count + 1);
			visit[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	team(0, 0);
	
	cout << ans << '\n';
	return 0;
}
