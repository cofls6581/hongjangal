#include <iostream>

using namespace std;

int T;
int ans;

int func(int n) {
	if (n == 0) 
		return ans++;
	if (n < 0) 
		return 0;
	return func(n-1) + func(n-2) + func(n-3);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int n;

	cin >> T;

	while (T) {
		cin >> n;
		ans = 0;
		func(n);
		cout << ans << endl;
		T--;
	}

	return 0;
}
