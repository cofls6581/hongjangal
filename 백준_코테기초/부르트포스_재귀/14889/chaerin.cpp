#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 21
using namespace std;
int n,ans=9999999;
int arr[MAX][MAX];
vector <int> start, link;
int ss, ls;

void func(int idx) {
	if (idx == n + 1) {
		if (start.size() == n / 2 && link.size() == n / 2) {
			ss = 0; ls = 0;
			for (int i = 0; i < n / 2; i++) {
				for (int j = i + 1; j < n / 2; j++) {
					if (i == j) continue;
					ss += arr[start[i]][start[j]] + arr[start[j]][start[i]];
					ls += arr[link[i]][link[j]] + arr[link[j]][link[i]];
				}
			}
			ans = min(ans, abs(ss - ls));
		}
		return;
	}
	start.push_back(idx);
	func(idx + 1);
	start.pop_back();
	link.push_back(idx);
	func(idx + 1);
	link.pop_back();
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> arr[i][j];
		}
	}
	func(1);
	cout << ans<<endl;

	return 0;
}
