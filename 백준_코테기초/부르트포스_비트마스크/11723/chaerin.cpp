#include <iostream>
#include <cstring>
using namespace std;

int testN;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> testN;
	string s = "";
	int n = 0, bit = 0;

	for (int i = 0; i < testN; ++i) {
		cin >> s;
		if (s[0] == 'a' && s[1] == 'd') {
			cin >> n;
			bit |= (1 << n);
		}
		else if (s[0] == 'r') {
			cin >> n;
			bit &= ~(1 << n);
		}
		else if (s[0] == 't') {
			cin >> n;
			bit ^= (1 << n);
		}
		else if (s[0] == 'a') {
			bit = (1 << 21) - 1;
		}
		else if (s[0] == 'e') {
			bit = 0;
		}
		else { //check
			cin >> n;
			if (bit & (1 << n))
				cout << "1\n";
			else
				cout << "0\n";
		}
	}

	return 0;
}