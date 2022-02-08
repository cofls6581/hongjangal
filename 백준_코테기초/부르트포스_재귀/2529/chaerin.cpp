#include <iostream>
#include <string>
#include <algorithm>
#define MAX 10
using namespace std;
int k;
string minN = "9876543210";
string maxN = "-9876543210";
char sign[MAX];
int arr[MAX + 1] = { 0, }; // 문자열 check용
int check[MAX] = { 0, }; //숫자 check용

int compare(int i) {
	if (sign[i] == '<' && arr[i] > arr[i + 1]) return 0;
	if (sign[i] == '>' && arr[i] < arr[i + 1]) return 0;
	return 1;
}

void func(int cnt) {
	if (cnt == k + 1) {
		for (int i = 0; i < cnt - 1; ++i) {
			if (!compare(i))
				return;
		}
		//case 통과
		string s;
		for (int i = 0; i < cnt; i++) {
			s += to_string(arr[i]);
		}
		// cout << s << endl; for debug
		if (s > maxN)
			maxN = s;
		if (s < minN)
			minN = s;
		return;
	}

	for (int i = 0; i <= 9; ++i) {
		if (check[i])
			continue;
		check[i] = 1;
		arr[cnt] = i;
		func(cnt + 1);
		check[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> sign[i];
	}
	func(0);
	cout << maxN << '\n' << minN << '\n';
	return 0;
}