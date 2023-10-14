#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> num;
vector <char> op;
int ans=-1e9;

int oper(char a, int b, int c) {
    if(a == '+') return b + c; 
    else if(a == '-') return b - c; 
    else return b * c;  
} 

void func (int idx, int cur){
    if(idx == num.size() - 1){ //기저 사례 
        ans = max(ans, cur); 
        return;
    }  

    func(idx + 1, oper(op[idx], cur, num[idx + 1]));
    if(idx + 2 <= num.size() - 1){
        int temp = oper(op[idx + 1], num[idx + 1], num[idx + 2]); 
        func(idx + 2, oper(op[idx], cur, temp));  
    } 
    return;
} 

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin>>n;
    string s;
    cin>>s;
    for(int i=0; i<n; ++i){
        if(i%2==0) num.push_back(s[i]-'0');
        else op.push_back(s[i]);
    }

    func(0,num[0]);
    cout << ans << "\n";
    return 0;
}
