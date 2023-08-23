#include <iostream>
#include <string>
#define prev myprev
#pragma warning(disable:4996)

using namespace std;
typedef pair<int, int> pp;
const int mx = 104;

int n;
int team[mx];
string goal[mx];
int score[3], winTime[3];
string prev;

string toStringTime(int intTime) {
    string mnt = "00" + to_string(intTime / 60);
    string sec = "00" + to_string(intTime % 60);
    return mnt.substr(mnt.size() - 2, 2) + ":" + sec.substr(sec.size() - 2, 2);
}

int toIntTime(string s) {
    return atoi(s.substr(0, 2).c_str()) * 60 + atoi(s.substr(s.size() - 2, 2).c_str());
}

int sub(string a, string b) { // a - b
    return toIntTime(a) - toIntTime(b);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> team[i];
        cin >> goal[i];
    }

    for (int i = 0; i < n; ++i) {
        if (score[1] != score[2]) {
            int win = (score[1] > score[2]) ? 1 : 2;
            winTime[win] += sub(goal[i], prev);
        }
        // 득점 반영
        score[team[i]]++;
        prev = goal[i];
    }
    // 마지막
    if (score[1] != score[2]) {
        int win = (score[1] > score[2]) ? 1 : 2;
        winTime[win] += sub("48:00", goal[n - 1]);
    }

    for (int i = 1; i <= 2; ++i) {
        cout << toStringTime(winTime[i]) << '\n';
    }

    return 0;
}
