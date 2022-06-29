#include <iostream>
#include <queue>
#include<set>
#include <tuple>
using namespace std;

long long s,t;
set<long long> check;
queue<pair<long long,string>> q;
const long long limit = 1000000000LL;

int bfs(){
    while(!q.empty()){
    long long x;
    string str;
    tie(x,str)=q.front(); 
    q.pop();
    if(x==t){ //정답인 케이스 
        if(str.length()==0){
            str='0';
        }
        cout<<str<<'\n';
        return 0;
    }
    //더 탐색 필요
    if(0<=x*x&&x*x<=limit&&check.count(x*x)==0){
        q.push(make_pair(x*x,str+"*"));
        check.insert(x*x);
    }
    if(0<=x+x&&x+x<=limit&&check.count(x+x)==0){
        q.push(make_pair(x+x,str+"+"));
        check.insert(x+x);
    }
    if(0<=x-x&&x-x<=limit&&check.count(x-x)==0){
        q.push(make_pair(x-x,str+"-"));
        check.insert(x-x);
    }
    if(0<=x/x&&x/x<=limit&&check.count(x/x)==0){
        q.push(make_pair(x/x,str+"/"));
        check.insert(x/x);
    }
   }
   cout<<-1<<'\n';
   return 0;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin>>s>>t;
    //로직
    q.push(make_pair(s,""));
    check.insert(s);
    bfs();
    return 0;
}
