#include <iostream>
#include <vector>
#define MAX 1000001
#define modN 1000000009

using namespace std;
long long dp[MAX] = { 0,1,2,4 };
vector <int> input;

void bottomup(long long max) {

	for (long long i = 4; i <= max; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % modN;
	}

}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	int t;
	cin >> t;

	int maxN = 0;
	int k;

	for (int i = 0; i < t; ++i) {
		cin >> k;
		input.push_back(k);
		if (maxN < input[i])
			maxN = input[i];
	}

	bottomup(maxN);

	t = input.size();
	for (int i = 0; i < t; ++i) {
		cout << dp[input[i]] << "\n";
	}

}