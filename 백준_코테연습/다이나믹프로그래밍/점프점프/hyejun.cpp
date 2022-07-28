#include <iostream>
#include <vector>

using namespace std;

  int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // input
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> d(n, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // dp
    d[0] = 0; // 시작칸
    for (int i = 0; i < n - 1; i++) { // 앞으로 갈 수 있는 칸 다 해보기
        if (d[i] == -1) continue; // 해당 칸까지 갈 수 있는 방법이 없으면 넘어감
        for (int j = 1; j <= a[i]; j++) {
            if (i + j >= n) { // n번째 칸 도달시 멈춤
                break;
            }
            if (d[i + j] == -1 || d[i + j] > d[i] + 1) { // i+j 번 칸으로 가는 첫번째 방법이거나 i를 통해서 가는게 최소인 경우
                d[i + j] = d[i] + 1;
            }
        }
    }

    // output
    cout << d[n - 1] << '\n';
    return 0;
}
