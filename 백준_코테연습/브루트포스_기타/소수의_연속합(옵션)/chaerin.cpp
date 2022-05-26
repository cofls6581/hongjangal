#include <iostream>
#include <vector>
using namespace std;
int n;
int ans=0;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin>>n;
    //소수로 된 배열 만들기 
    vector <bool> check(n+1);
    vector <int> prime;
    for (int i=2; i<=n; i++) {
        if (check[i] == false) {
            prime.push_back(i);
            for (int j=i*2; j<=n; j+=i) {
                check[j] = true;}
        }
    }
    //로직
    int left=0; int right=0;
    int sum;
    if(prime.empty()) sum=0;
    else sum=prime[0];

    while(left<=right&&right<prime.size()){
        if(sum<n){
            right++;  
            sum+=prime[right];
        }else if(sum>n){
        sum-=prime[left];
        left++;
        //left,right 같은 위치에 있었을 경우 해결
        if(left>right && left<n){
            right=left;
            sum=prime[left];
            }
        }else if(sum==n){
            ans++;
            right++;
            sum+=prime[right];
        }
    }

    //output
    cout<<ans<<'\n';    
    return 0;
}
