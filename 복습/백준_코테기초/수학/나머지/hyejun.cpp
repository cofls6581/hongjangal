/*
나머지 값을 인덱스로 갖는 bool형 check 배열을 활용함. 해당 나머지 값이 최초로 나온 경우에만 cnt를 증가시킴.
*/
#include <iostream>

using namespace std;

int arr[10];
bool check[42];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
        int x = arr[i] % 42;
        if (check[x] == false) {
            check[x] = true;
            cnt++;
        }
    }
    cout << cnt << '\n';

    return 0;
}
