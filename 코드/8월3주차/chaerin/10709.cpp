#include <bits/stdc++.h>
using namespace std;

#define MAX 102

int h,w;
int cloud[MAX][MAX];

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin>>h>>w;
    string s;
    for(int i=0; i<h; ++i){
        cin>>s;
        for(int j=0; j<w; ++j){
            if(s[j] == '.') cloud[i][j] = -1;
			else cloud[i][j] = 0;
        }
    }

    for(int i=0; i<h; ++i){
        for(int j=0; j<w; ++j){
            if(cloud[i][j]==0){
                int cnt=1;
                while(cloud[i][j+1]==-1){
                    cloud[i][j+1]=cnt;
                    cnt++; j++;
                }
            }
        }
    }

    for(int i=0; i<h; ++i){
        for(int j=0; j<w; ++j){
            cout<<cloud[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}
