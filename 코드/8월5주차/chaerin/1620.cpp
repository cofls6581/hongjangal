#include <iostream>
#include <cctype>
#include<map>
using namespace std;
#define MAX 100002

int n,m;
map<string, int> mp;
map<int, string> mp2;
string a[MAX];
string s;

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin>>n>>m;
    for(int i=1; i<=n; ++i){
        cin >> s; 
		mp[s] = i;  
		mp2[i] = s; 
        a[i] = s;
    }

    for(int i=0; i<m; ++i){
        cin>>s;
        if(isalpha(s[0])){ //알파벳
            cout<<mp[s]<<'\n';
        }
        else{ //숫자
            cout<<a[stoi(s)]<<'\n';
        }
    }
    
    return 0;
}
