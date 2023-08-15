#include <bits/stdc++.h>
using namespace std;

int n;
char arr[66][66];

string quard(int x, int y, int size){
    if(size==1){
        return string(1,arr[x][y]);
    }
    string ans="";
    char b =arr[x][y];
    for(int i=x;i<x+size;++i){
        for(int j=y; j<y+size;++j){
            if(b!=arr[i][j]){
                ans+='(';
                //z자 확인
                ans+=quard(x,y,size/2);
                ans+=quard(x,y+size/2,size/2);
                ans+=quard(x+size/2,y,size/2);
                ans+=quard(x+size/2,y+size/2,size/2);
                ans+=')';
                return ans;
            }
        }
    }
    return string(1,arr[x][y]); //전부 0또는1
}

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n;

    string s;
    for(int i=0;i<n;++i){
        cin>>s;
        for(int j=0;j<n;++j){
            arr[i][j]=s[j];
        }
    }

    cout << quard(0, 0, n) << '\n'; 
    return 0;
}
