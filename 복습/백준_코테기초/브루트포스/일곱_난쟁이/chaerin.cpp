/*
먼저 난쟁이의 키를 오름차순으로 출력해야되는 걸 보고 정렬 함수를 사용해야겠다는 생각을 했다.
또한, 시간 제한이 2초인 것을 보고 브루트포스를 활용해 문제를 풀어도 되겠다는 생각이 들었다.
선택될 난쟁이들을 넣으면서 구할지 아니면 전체에서 빼면서 구할지 고민하다가 뺴는 게 더 간단할 것 같아서
전체에서 두 난쟁이를 픽해 빼가면서 100이 되는 경우의 수를 찾는 방식을 활용했다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int height[9];
int sum = 0;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input
    for (int i = 0; i < 9; i++) {
		cin >> height[i];
		sum += height[i];
	}

    //logic
    bool isFind=false;
    for (int i = 0; i < 8; ++i) {
		sum = sum - height[i];
		for (int j = 1; j < 9; ++j) {
			sum = sum - height[j];
			if (sum == 100) {
				height[i] = 0;
				height[j] = 0;
                isFind=true;
				break;
			}
			else 
			  sum = sum + height[j];
		}
        if(isFind) break;
		sum = sum + height[i];
	}
    sort(height, height + 9);

    //output
    for (int i = 2; i < 9; i++){
		cout << height[i] << "\n";
    }
    return 0;
}
