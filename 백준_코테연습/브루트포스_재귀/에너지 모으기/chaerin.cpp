#include <iostream>
#include <vector>
using namespace std;

int n;
vector <int> a;

int solve(vector <int> &a){
    int n=a.size();
    //정답인 경우
    if(n==2) 
        return 0;
    //다음 경우 호출
    int ans=0;
    for(int i=1;i<n-1;++i){ //뽑는 수 x가 i
        int energy=a[i-1]*a[i+1];
        vector <int> b(a);
        b.erase(b.begin()+i);
        energy+=solve(b);
        if(ans<energy)
            ans=energy;
    }
    return ans;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin>>n;
    int x;
    for(int i=0;i<n;++i){
        cin>>x;
        a.push_back(x);
    }
    // 로직+output
    cout<<solve(a)<<'\n';
    return 0;
}
