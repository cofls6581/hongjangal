#include <iostream>
#include <vector>
#include <algorithm>
# define MAX 21
using namespace std;

int N,ans=99999999;
int arr[MAX][MAX];
vector <int> start, link;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < (1 << N); ++i) {

		start.clear();
		link.clear();

		for (int k = 0; k < N; k++) { 	//0이면 start 팀원
			if ((i & (1 << k)) == 0) {
				start.push_back(k);
			}
			else {
				link.push_back(k);
			}
		}

		if (start.size() > N / 2) continue;
		if (link.size() > N / 2) continue;


		int ss = 0;
		int ls = 0;
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				if (i == j) continue;
				ss += arr[start[i]][start[j]];
				ls += arr[link[i]][link[j]];
			}
		}

		ans = min(ans ,abs(ss - ls));
	}


	cout << ans << '\n';
	return 0;
}
