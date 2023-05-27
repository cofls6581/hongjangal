/**
 * @file 5648.cpp
 * @date 2023-05-28
 * 문자열로 받아서 reverse 함수 활용해 뒤집은 후 stoll 함수 사용
 */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
string s;
vector<long long> v;

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>s;
        reverse(s.begin(), s.end());
        v.push_back(stoll(s));
    }
    sort(v.begin(),v.end());
    for(auto i:v){
        cout<<i<<'\n';
    }

    return 0;
}
