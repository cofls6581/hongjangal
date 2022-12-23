/*
난쟁이 키를 오름차순으로 정렬하여 출력 => 미리 정렬하여 추가적인 계산 없도록 함
전체에서 두 난쟁이의 키를 빼서 일곱 난쟁이의 키가 100이 되는지 확인.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int height[9];
	int sum = 0;
	int i1, i2; // 제외되는 난쟁이의 인덱스
	bool flag = false;

	for (int i = 0; i < 9; i++) {
		cin >> height[i];
		sum += height[i];
	}
	sort(height, height+9);

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - (height[i] + height[j]) == 100) {
				i1 = i; i2 = j;
				flag = true; 
				break;
			}
		}
		if (flag == true) break;
	}

	for (int i = 0; i < 9; i++) {
		if (i == i1 || i == i2) continue;
		cout << height[i] << '\n';
	}
	return 0;
}
