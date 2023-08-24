#include <bits/stdc++.h>
using namespace std;

int a[10];

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);

    for(int i=0;i<9;++i){
        cin>>a[i];
    }

    for(int i=0; i<9 ;++i){
        int ans=0;
        for(int j=i+1; j<9; ++j){
            for(int k=0; k<9 ;++k){
                if(k!=i&&k!=j){
                    ans+=a[k];
                }
            }
            if(ans==100){
                a[i]=a[j]=103;
                sort(a,a+9);
                for(int i=0; i<7; ++i){
                    cout<<a[i]<<'\n';
                }
                return 0;
            }
            ans=0;
        }
    }
    return 0;
}
