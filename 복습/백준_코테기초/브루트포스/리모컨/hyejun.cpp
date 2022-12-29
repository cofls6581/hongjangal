/*
완전 탐색 진행. 눌러야 하는 (숫자버튼 개수) + (플러스/마이너스 버튼 개수) = (총 개수) 를 구해서 최솟값 갱신.
*/
#include <iostream>
#include <cmath>

using namespace std;

int n, m;
bool broken[10];

int number_button(int channel) { // 해당 채널로 이동하기 위해서 눌러야 하는 '숫자 버튼'의 개수 반환
    if (channel == 0) { // 이동하려는 채널이 0 인 경우 예외 처리
        if (broken[channel]) return 0;
        else return 1;
    }

    int cnt = 0;
    while (channel > 0) {
        if (broken[channel % 10]) return 0; // 고장난 버튼인 경우
        channel /= 10;
        cnt++;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        broken[x] = true;
    }

    int ans = abs(n - 100); // +/- 버튼으로만 이동하는 횟수로 초기화
    for (int i = 0; i < 1000000; i++) {
        int numberCnt = number_button(i); // 눌러야 하는 '숫자 버튼'의 개수
        if (numberCnt > 0) {
            int plusMinusCnt = abs(i - n); // 눌러야 하는 '+/- 버튼'의 개수
            int tmp = numberCnt + plusMinusCnt; // 총 개수
            if (ans > tmp) {
                ans = tmp;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
