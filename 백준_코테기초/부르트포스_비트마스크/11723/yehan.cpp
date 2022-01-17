#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int testcase;
	cin >> testcase;

	int S = 0;

	while (testcase--) {
		int num;
		string str;
		cin >> str;

		if (str == "add") {
			cin >> num;
			S |= (1 << num);
		}
		else if (str == "remove") {
			cin >> num;
			S &= ~(1 << num);
		}
		else if (str == "check") {
			cin >> num;
			if (S & (1 << num)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (str == "toggle")
		{
			cin >> num;
			S ^= (1 << num);
		}
		else if (str == "all") {
			S = -1;
		}
		else if (str == "empty") {
			S = 0;
		}
	}
}