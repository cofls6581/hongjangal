#include <bits/stdc++.h>
using namespace std;

int n;
vector <string> ans;
string s;
string ret="";

bool cmp(string a, string b) {
    if(a.size() == b.size()) return a < b;
    return a.size()<b.size();
}

void func(){   
	while(true){ // 제일 앞 0 연속 제거
		if(ret.front() == '0') ret.erase(ret.begin()); 
		else break;
	}
	if(ret.size() == 0) ret = "0"; //0만 존재할 경우 0 다 제거되므로 추가
	ans.push_back(ret);
	ret = "";  
}

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n;
    while(n--){
        cin>>s;
        ret="";
        for(int i=0; i<s.size();++i){
            if(s[i]<65) ret += s[i];
            else if(ret.size()) func();
        }
        if(ret.size()) func(); //마지막 처리
    }

    sort(ans.begin(), ans.end(), cmp);
    for(string i : ans) cout << i << "\n";
    return 0;
}
