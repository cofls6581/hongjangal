#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int solve(vector<vector<int> > &a, vector <int> &b){
    vector <int> zero,one;
    for(int i=0;i<n;++i){
        if(b[i])
            one.push_back(i);
        else
            zero.push_back(i);
    }
    int z=0; int o=0;
    for(int i=0;i<n/2;++i){
        for(int j=0;j<n/2;++j){
            if(i==j)
                continue;
            z+=a[zero[i]][zero[j]];
            o+=a[one[i]][one[j]];
        }
    }
    int diff=abs(z-o);
    return diff;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin>>n;
    vector<vector<int> > arr(n,vector<int>(n));
    for(int i=0;i<n;++i){
        for(int j=0; j<n; ++j){
            cin>>arr[i][j];
        }
    }
    //로직
    vector <int> b(n);
    for(int i=0;i<n/2;++i){
        b[i]=1;
    }
    sort(b.begin(),b.end());
    int ans=999999999;
    do{
        int diff=solve(arr,b);
        if(ans>diff) ans=diff;
    }while(next_permutation(b.begin(),b.end()));
    //output
    cout<<ans<<'\n';
    return 0;
}
