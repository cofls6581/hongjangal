#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int solve(vector <int> &a, vector<int>&b){
    int ans=a[0];
    for(int i=1;i<n;++i){
        if(b[i-1]==0){
            ans+=a[i];
        }
        else if(b[i-1]==1){
            ans-=a[i];
        }
        else if(b[i-1]==2){
            ans*=a[i];
        }
        else{
            ans/=a[i];
        }
    }
    return ans;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    vector <int> b;
    int x;
    for(int i=0;i<4;++i){ //0:+,1:-,2:*,3:/
        cin>>x;
        for(int j=0;j<x;++j){
            b.push_back(i);
        }
    }
    //로직
   vector <int> ans;
   do{
       int tmp=solve(a,b);
       ans.push_back(tmp);
   } while(next_permutation(b.begin(),b.end()));
    //output
    auto k=minmax_element(ans.begin(),ans.end());
    cout<<*k.second<<'\n'<<*k.first<<'\n';
    return 0;
}
