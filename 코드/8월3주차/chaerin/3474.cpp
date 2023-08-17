#include <bits/stdc++.h>
using namespace std;

int t;
int input;

int main (){
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin>>t;
    int tn,fn;
    while(t--){
        cin>>input;
        tn=0;fn=0;
        for(int i=2; i<=input; i*=2){
            tn+=input/i;
        }
        for(int i=5; i<=input; i*=5){
            fn+=input/i;
        }
        cout<<min(tn,fn)<<'\n';
    }

    return 0;
}
