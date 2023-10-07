#include <bits/stdc++.h>

using namespace std;

bool cmp(const string &a, const string &b){
    return a+b>b+a;
}

string solution(vector<int> nums) {
    string answer = "";
    vector <string> v;
    for(int i=0; i<nums.size();++i){
        v.push_back(to_string(nums[i]));
    }
    sort(v.begin(),v.end(),cmp);
    for (int i=0; i<v.size(); i++) {
        answer += v[i];
    }
    if(answer[0]=='0') answer='0';
    return answer;
}
