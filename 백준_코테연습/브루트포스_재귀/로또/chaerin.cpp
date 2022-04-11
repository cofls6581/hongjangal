#include <iostream>
#include <vector>
using namespace std;
vector <int> lotto;

void solve(vector<int>&a,int index, int cnt){
    //정답 케이스
    if(cnt==6){
        for(int i=0;i<6;++i) 
            cout<<lotto[i]<<" ";
        cout<<"\n";
        return;
    }
    //정답 도출 불가능한 케이스
    int n=a.size();
    if(n==index) return;
    //다음 호출 필요 케이스
    //현재 인덱스 포함 o
    lotto.push_back(a[index]);
    solve(a,index+1,cnt+1);
    //현재 인덱스 포함 x
    lotto.pop_back();
    solve(a,index+1,cnt);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    while(true){
        int k;
        cin>>k;
        if(k==0)
            break;
        vector <int> a(k);
        int n;
        for(int i=0;i<k;++i){
            cin>>a[i];
        }
        solve(a,0,0);
        cout<<"\n";
    }
    return 0;
}
