#include <iostream>
#include <string>
#include <stack>
#pragma warning(disable:4996)

using namespace std;

string s;

bool check(string s) {
    stack<char> stk1, stk2, stk3;
    // '(' 나 '{' 가 오면 스택에 push
    // ')' 나 '}' 가 오면 스택에서 pop (만약 스택에 아무것도 없으면 바로 false)
    // 마지막에 스택이 비었으면 true, 안 비었으면 false
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            stk1.push(s[i]);
            stk3.push(s[i]);
        }
        else if (s[i] == '[') {
            stk2.push(s[i]);
            stk3.push(s[i]);
        }
        else if (s[i] == ')') {
            if (stk1.size() && stk3.top() == '(') {
                stk1.pop(); stk3.pop();
            }
            else return false;
        }
        else if (s[i] == ']') {
            if (stk2.size() && stk3.top() == '[') {
                stk2.pop(); stk3.pop();
            }
            else return false;
        }
    }
    return stk1.empty() && stk2.empty();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    while (1) {
        getline(cin, s);
        if (s[0] == '.') break;
        if (check(s)) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}
