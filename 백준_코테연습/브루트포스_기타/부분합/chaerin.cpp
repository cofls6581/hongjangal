#include <iostream>
#include <vector>
using namespace std;

int n,s;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin>>n>>s;
    vector <int> input(n);
    for(int i=0;i<n;++i){
        cin>>input[i];}
    //로직
    int left=0; int right=0;
    int sum=input[0]; 
    int ans=n+1;
    while(left<=right&&right<n){
        if(sum<s){
            right++;  
            sum+=input[right];
        }else if(sum>s){
            if(right-left+1<ans)
                ans=right-left+1;
            sum-=input[left];
            left++;
        }else if(sum==s){
            if(right-left+1<ans)
                ans=right-left+1;
            right++;
            sum+=input[right];
        }
    }
    //output
    if(ans>=n+1) ans=0;
    cout<<ans<<'\n';
    return 0;
}
