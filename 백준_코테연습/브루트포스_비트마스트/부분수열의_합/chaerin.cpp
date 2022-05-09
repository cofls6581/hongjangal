#include <iostream>
#include <vector>
using namespace std;

int n;
bool check[20*100000+1];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    //로직
    for(int i=0;i<(1<<n);++i){
        int sum=0;
        for(int j=0;j<n;++j){
            if(i&(1<<j)){
                sum+=a[j];
            }
        }
        check[sum]=true;
    }
    //output
    for(int i;;i++){
        if(!check[i]){
            cout<<i<<'\n';
            break;
        }
    }
    return 0;
}
