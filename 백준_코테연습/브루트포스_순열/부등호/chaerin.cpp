#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k;

bool check(vector <char> &input, vector <int> &num){
    for(int i=0;i<input.size();++i){
        if(input[i]=='<'&&num[i]>num[i+1]){
            return false;
        }
        if(input[i]=='>'&&num[i]<num[i+1]){
            return false;
        }
    }
    return true;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin>>k;
    vector <char> input(k);
    for(int i=0; i<k;++i){
        cin>>input[i];
    }
    //로직
    //초기 세팅
    vector <int> max(k+1);
    vector <int> min(k+1);
    for(int i=0;i<=k;++i){
        max[i]=9-i;
        min[i]=i;
    } 
    //순열 사용
    do{
       if(check(input,min)){
           break;
       }
    }while(next_permutation(min.begin(),min.end()));
    do{
        if(check(input,max)){
           break;
       }
    }while(prev_permutation(max.begin(),max.end()));
    //output
    for(int i=0;i<=k;++i){
        cout<<max[i];
    }
    cout<<'\n';
    for(int i=0;i<=k;++i){
        cout<<min[i];
    }
    cout<<'\n';
    return 0;
}
