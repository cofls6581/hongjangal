#include <iostream>
#include <string>

using namespace std;

int M, x, bits;
string s;

void add(int a) {
	bits |= (1 << a);
}

void remove(int a) {
	bits &= ~(1 << a);
}

bool check(int a) {
	return bits & (1 << a);
}

void toggle(int a) {
	bits ^= (1 << a);
}

void all() {
	bits = ((1 << 21) - 1);
}

void empty() {
	bits = 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> s;
		if (s == "add") {
			cin >> x;
			add(x);
			continue;
		}
		else if (s == "remove") {
			cin >> x;
			remove(x);
			continue;
		}
		else if (s == "check") {
			cin >> x;
			cout << check(x) << '\n';
			continue;
		}
		else if (s == "toggle") {
			cin >> x;
			toggle(x);
			continue;
		}
		else if (s == "all") {
			all();
			continue;
		}
		else if (s == "empty") {
			empty();
			continue;
		}
	}
	return 0;
}