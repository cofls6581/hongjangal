#include <iostream>
#include <string>
#include <algorithm>

#define MAX 608
using namespace std;

int arr[MAX][MAX];
int  H, W, X, Y;

void func() {
	for (int i = X+1; i <= H; i++) {
		for (int j = Y+1; j <= W; j++) {
			arr[i][j] -= arr[i - X][j - Y];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	cin >> H >> W >> X >> Y;
	for (int i = 1; i <= H + X; i++) {
		for (int j = 1; j <= W + Y; j++) {
			cin >> arr[i][j];
		}
	}

	func();

	for (int i = 1; i <= H ; i++) {
		for (int j = 1; j <= W ; j++) {
			cout<< arr[i][j]<<" ";
		}
		cout << "\n";
	}
	return 0;
}
