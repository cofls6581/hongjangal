/*
가로로 교환하는 경우, 세로로 교환하는 경우에 대해 최대 길이를 구함.
가장 긴 연속 부분이 상,하,좌,우 로 연결된 것이 아닌, 막대 모양을 말한다는 점에 주의해야 함. 
(처음에 문제를 잘못 읽어서 dfs로 상,하,좌,우 를 탐색함.)
*/
#include <iostream>
#include <algorithm>
#define MAX 50

using namespace std;

int n, ans = 0;
char arr[MAX][MAX];

void get_max() { // 최대 길이 탐색
    for (int i = 0; i < n; i++) { // 가로
        int cnt = 1;
        for (int j = 0; j < n - 1; j++) {
            if (arr[i][j] == arr[i][j + 1]) {
                cnt++;
                if (cnt > ans) ans = cnt;
            }
            else {
                cnt = 1;
            }
        }
    }
    for (int j = 0; j < n; j++) { // 세로
        int cnt = 1;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i][j] == arr[i + 1][j]) {
                cnt++;
                if (cnt > ans) ans = cnt;
            }
            else {
                cnt = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    // 양옆 바꾸기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            swap(arr[i][j], arr[i][j + 1]);
            get_max();
            swap(arr[i][j], arr[i][j + 1]);
        }
    }
    // 위아래 바꾸기
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - 1; i++) {
            swap(arr[i][j], arr[i + 1][j]);
            get_max();
            swap(arr[i][j], arr[i + 1][j]);
        }
    }
    cout << ans << '\n';

    return 0;
}
