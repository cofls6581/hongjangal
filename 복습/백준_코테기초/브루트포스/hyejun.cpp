/*
조합 문제로 생각해서 재귀 함수를 사용함.
답을 찾은 경우 바로 프로그램을 종료하기 위해 exit(0)을 이용함.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int height[9];
vector<int> seven;

void solve(int idx, int cnt, int sum) {
    if (cnt == 7) {
        if (sum == 100) {
            sort(seven.begin(), seven.end());
            for (int i = 0; i < seven.size(); i++) {
                cout << seven[i] << '\n';
            }
            exit(0);
        }
        else return;
    }
    for (int i = idx; i < 9; i++) {
        seven.push_back(height[i]);
        solve(idx + 1, cnt + 1, sum + height[i]);
        seven.pop_back();

        solve(idx + 1, cnt, sum);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 0; i < 9; i++) {
        cin >> height[i];
    }
    solve(0, 0, 0);
}
