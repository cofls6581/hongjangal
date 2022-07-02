#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <set>

using namespace std;

const long long limit = 1000000000LL;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// input
	long long s, t;
	cin >> s >> t;
	
	// BFS
	set<long long> visited; // 방문 여부 체크
	queue<pair<long long, string>> q;
	q.push(make_pair(s, ""));
	visited.insert(s);
	
	while (!q.empty()) {
		long long cur;
		string str; // 경로
		tie(cur, str) = q.front();
		q.pop();

		if (cur == t) { // t로 바꿨으면 출력
			if (str.length() == 0) { // s와 t가 같은 경우
				str = "0";
			}
			cout << str << '\n';
			return 0;
		}
		// *, +, -, / 순으로 연산
		if (0 <= cur * cur && cur * cur <= limit && visited.count(cur * cur) == 0) {
			q.push(make_pair(cur * cur, str + "*"));
			visited.insert(cur * cur);
		}
		if (0 <= cur + cur && cur + cur <= limit && visited.count(cur + cur) == 0) {
			q.push(make_pair(cur + cur, str + "+"));
			visited.insert(cur + cur);
		}
		if (0 <= cur - cur && cur - cur <= limit && visited.count(cur - cur) == 0) {
			q.push(make_pair(cur - cur, str + "-"));
			visited.insert(cur - cur);
		}
		if (cur != 0 && 0 <= cur / cur && cur / cur <= limit && visited.count(cur / cur) == 0) { // 0 조건 처리
			q.push(make_pair(cur / cur, str + "/"));
			visited.insert(cur / cur);
		}
	}
	cout << -1 << '\n'; // t로 바꿀 수 없는 경우
	return 0;
}
