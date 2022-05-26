#include <iostream>
#include <vector>
using namespace std;

long n,m;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin >>n>>m;
    vector <int> input(n);
    for(int i=0;i<n;++i){
        cin>>input[i];}
    //로직, 투포인터 사용
    int left=0; int right=0;
    int sum=input[0]; 
    int ans=0;
    while(left<=right&&right<n){
        if(sum<m){
            right++;  
            sum+=input[right];
        }else if(sum>m){
        sum-=input[left];
        left++;
        //left,right 같은 위치에 있었을 경우 해결
        if(left>right && left<n){
            right=left;
            sum=input[left];
            }
        }else if(sum==m){
            ans++;
            right++;
            sum+=input[right];
        }
    }
    //output
    cout<<ans<<'\n'; 
    return 0;
}
