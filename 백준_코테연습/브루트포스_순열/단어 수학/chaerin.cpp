#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

char alpha[256];
int n;

int calc(vector<string> &a, vector<char> &letters, vector<int> &d) {
    int m = letters.size();
    int sum = 0;
    for (int i=0; i<m; i++) {
        alpha[letters[i]] = d[i];
    }
    for (string s : a) {
        int now = 0;
        for (char x : s) {
            now = now * 10 + alpha[x];
        }
        sum += now;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> n;

    vector<string> a(n); //인풋 문자열
    vector<char> letters; //중복없는 알파벳

    for (int i=0; i<n; i++) {
        cin >> a[i];
        for (char x : a[i]) {
            letters.push_back(x);
        }
    }

    sort(letters.begin(), letters.end());
    letters.erase(unique(letters.begin(), letters.end()), letters.end());
    
    //9부터 숫자 담기
    int m = letters.size();
    vector<int> d;
    for (int i=9; i>9-m; i--) {
        d.push_back(i);
    }
    sort(d.begin(), d.end());

    int ans = 0;
    do {
        int now = calc(a, letters, d);
        if (ans < now) 
            ans = now;
    } while (next_permutation(d.begin(), d.end()));

    cout << ans << '\n';
    
    return 0;
}
