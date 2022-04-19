#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int plusop,minusop,mulop,divop;
vector <int> num;

pair<int,int> go( int idx, int cur, int plusop, int minusop, int mulop, int divop){
    //정답 케이스
    if(idx==n){
        return make_pair(cur,cur);
    }

    //다음 호출
    vector<pair<int,int>> result;
    if(plusop>0)
        result.push_back(go(idx+1,cur+num[idx],plusop-1,minusop,mulop,divop));

    if(minusop>0)
        result.push_back(go(idx+1,cur-num[idx],plusop,minusop-1,mulop,divop));
    
    if(mulop>0)
        result.push_back(go(idx+1,cur*num[idx],plusop,minusop,mulop-1,divop));

    if(divop>0)
        result.push_back(go(idx+1,cur/num[idx],plusop,minusop,mulop,divop-1));
    
    //최대 최소 구하기
    pair<int,int> ans=result[0];
    for(auto p:result){
        if(ans.first<p.first) //max
            ans.first=p.first; 
        if(ans.second>p.second) //min
            ans.second=p.second;
    }

    return ans;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin>> n;
    int k;
    for(int i=0;i<n;++i){
        cin >> k;
        num.push_back(k);
    }
    cin >> plusop >> minusop>>mulop>>divop;

    pair<int,int> p = go(1,num[0],plusop,minusop,mulop,divop);
    
    cout<<p.first<<'\n';
    cout<<p.second<<'\n';

    return 0;
}
