/*
N은 벡터의 최솟값 * 최댓값이므로 <algorithm> 헤더의 min_element(), max_element()를 사용함.
처음에 매개변수로 v.begin() + x 가 아닌 v.end()를 넣는 실수를 해서 답이 계속해서 0으로 나왔었음.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int x;
    vector<int> v(50);

    cin >> x;
    for (int i = 0; i < x; i++) {
        cin >> v[i];
    }

    cout << (*min_element(v.begin(), v.begin() + x)) * (*max_element(v.begin(), v.begin() + x)) << '\n';

    return 0;
}
