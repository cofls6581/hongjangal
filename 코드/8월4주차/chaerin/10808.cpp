#include<bits/stdc++.h>
using namespace std;

string s;
int arr[28]={0,};

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>s;
    for(int i=0; i<s.size(); ++i){
        arr[s[i]-'a']++;
    }

    for(int i=0; i<26; ++i){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';

    return 0;
}
