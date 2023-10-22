#include <bits/stdc++.h>

using namespace std;
int cnt, n;
vector<int> v;

int calc(vector<int> &numbers) {
    int res=0;
    for(int i=0; i<v.size(); ++i) {
        if(v[i]==0) { // -
            res-=numbers[i];
        }
        else { // +
            res+=numbers[i];
        }
    }
    return res;
}

void go(vector<int> &numbers, int target) {
    if(v.size()==n) { // n개 부호 다 골랐으면
        if(calc(numbers)==target) cnt++;
        return;
    }
    for(int i=0;i<2;++i) {
        v.push_back(i);
        go(numbers, target);
        v.pop_back();
    }
}

int solution(vector<int> numbers, int target) {
    n = numbers.size();
    go(numbers, target);
    return cnt;
}
