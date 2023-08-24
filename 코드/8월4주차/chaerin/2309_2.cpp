#include <bits/stdc++.h>
using namespace std;

int a[10];
vector <int> v;

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    
    for(int i = 0; i < 9; i++){
        cin >> a[i]; 
    }
    sort(a, a + 9);

    do{
        int ans=0;
        for(int i=0; i<7 ;++i){
            ans+=a[i];
        }
        if(ans==100) break;
    }while(next_permutation(a,a+9));

    for(int i=0; i<7 ;++i){
        cout<<a[i]<<'\n';
    }

    return 0;
}
