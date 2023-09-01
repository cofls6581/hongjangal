#include <iostream>
#include <vector>
#include <algorithm>
#pragma warning(disable:4996)

using namespace std;

typedef pair<int, int> pp;
const int mx = 13, n = 9;
int a[mx], sum[mx], fake[mx];
vector<int> v;

void find() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (sum[n] - (a[i] + a[j]) == 100) {
                fake[i] = 1;
                fake[j] = 1;
                return;
            }
        }
    }
    return;
}

void getSeven() {
    for (int i = 1; i <= n; ++i) {
        if (!fake[i]) v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    find();
    getSeven();
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << '\n';
    }

    return 0;
}
