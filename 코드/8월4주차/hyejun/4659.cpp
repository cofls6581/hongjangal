#include <iostream>
#pragma warning(disable:4996)

using namespace std;

string s;
int v_cnt, n_cnt, exist_v, flag;
char past;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    while (1) {
        cin >> s;
        if (s == "end") break;

        v_cnt = 0;
        n_cnt = 0;
        exist_v = 0;
        flag = 0;
        past = '0';

        for (int i = 0; i < s.size(); ++i) {
            // 모음인지 자음인지 체크
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                v_cnt++;
                n_cnt = 0;
                exist_v = 1;
            }
            else {
                n_cnt++;
                v_cnt = 0;
            }
            if (v_cnt == 3 || n_cnt == 3) flag = 1;
            // 연속 같은 글자 2번 체크
            if ((i >= 1) && (s[i] == past) && (s[i] != 'e') && (s[i] != 'o')) flag = 1;
            past = s[i];
        }
        if (exist_v == 0) flag = 1;

        if (flag) cout << '<' << s << "> is not acceptable.\n";
        else cout << '<' << s << "> is acceptable.\n";
    }

    return 0;
}
