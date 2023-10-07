#include <bits/stdc++.h>
using namespace std;

int k;
bool visited[10];
vector <char> v;
vector<string> ret;  

bool check(char x, char y, char op){
    if(x < y && op == '<') return true; 
	if(x > y && op == '>') return true; 
	return false; 
}

void dfs(string cur, int cnt){
    if(cnt==k+1){
    ret.push_back(cur); 
    return;
    }

    for(int i=0; i<10; ++i){
        if(visited[i]) continue;
        if(cnt==0||check(cur[cnt-1],i+'0',v[cnt-1])){
            visited[i]=1;
            dfs(cur+to_string(i),cnt+1);
            visited[i]=0;
        }
    }
}

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>k;
    char c;
    for(int i=0; i<k; ++i){
        cin>>c;
        v.push_back(c);
    }
    dfs("",0);
    sort(ret.begin(), ret.end());
    cout << ret[ret.size() - 1] << "\n" << ret[0] << "\n";
    return 0;
}
