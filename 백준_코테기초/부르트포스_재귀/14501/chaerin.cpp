#include <iostream>
#include <algorithm>
#define MAX 16
using namespace std;

int N;
int arr[MAX][2];
int ans =0;

void func(int day,int sum,int add) {
	if (day == N + 1) {
		ans = max(ans, sum);
		return;
	}
	else if (day > N + 1) {
		ans = max(ans, sum - add);
		return;
	}

	for (int i = day + arr[day][0]; i <= N+ arr[day][0]; ++i)
		func(i,sum+arr[day][1],arr[day][1]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; ++i) 
		cin >> arr[i][0] >> arr[i][1];

	for (int i = 1; i <= N; ++i)
		func(i, 0, 0);
	cout << ans;
	return 0;
}
