#include <iostream>
#include <vector>
#pragma warning(disable:4996)

using namespace std;

const int mx = 68;
char a[mx][mx];
int n;

string go(int y, int x, int len) { // len : 한 변의 길이, (y, x) : 시작점 좌표 (왼쪽 위 꼭짓점)
    if (len == 1) {
        return string(1, a[y][x]);
    }
    
    char val = a[y][x];
    string ret = "";
    for (int i = y; i < y + len; ++i) {
        for (int j = x; j < x + len; ++j) {
            if (a[i][j] != val) {
                ret += '(';
                ret += go(y, x, len / 2);
                ret += go(y, x + len / 2, len / 2);
                ret += go(y + len / 2, x, len / 2);
                ret += go(y + len / 2, x + len / 2, len / 2);
                ret += ')';
                return ret;
            }
        }
    }
    
    return string(1, a[y][x]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < n; ++j) {
            a[i][j] = s[j];
        }
    }

    cout << go(0, 0, n) << '\n';

    return 0;
}
