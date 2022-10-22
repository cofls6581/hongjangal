#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int r,c,k;
int A[100][100];
int n=3,m=3; //행,열


int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input
    cin>>r>>c>>k;
    r-=1; c-=1;
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            cin>>A[i][j];
        }
    }

    //logic+output
    if(A[r][c]==k){ //바로 정답 case
        cout<<0<<'\n';
        return 0;}

    for(int t=1;t<=100;++t){
        if(n>=m){ //R 연산(n>=m)
            int tmpM=m;
            for(int i=0;i<n;++i){
                map<int,int> d; //i행에서 인덱스 숫자 존재 횟수
                for(int j=0;j<m;++j){
                    if(A[i][j]==0){ //0은 pass
                        continue;}
                    d[A[i][j]]+=1;
                }
                vector<pair<int,int>> v;
                for(auto &p : d){
                    v.push_back(make_pair(p.second,p.first));
                }
                sort(v.begin(),v.end()); //v 첫번째 값 기준으로 정렬
                int l=min(50,(int)v.size());
                for(int j=0;j<l;j++){
                    A[i][j*2]=v[j].second;
                    A[i][j*2+1]=v[j].first;
                }
                for(int j=l*2;j<100;++j){
                    A[i][j]=0; //나머지 0으로 확장
                }
                if(tmpM<(int)v.size()*2){
                    tmpM=(int)v.size()*2;
                }
            }
            m=tmpM;
        }
        else{ //C 연산(n<m)
            int tmpN=n;
            for(int j=0;j<m;++j){
                map<int,int> d; //i행에서 인덱스 숫자 존재 횟수
                for(int i=0;i<n;++i){
                    if(A[i][j]==0){ //0은 pass
                        continue;}
                    d[A[i][j]]+=1;
                }
                vector<pair<int,int>> v;
                for(auto &p : d){
                    v.push_back(make_pair(p.second,p.first));
                }
                sort(v.begin(),v.end()); //v 첫번째 값 기준으로 정렬
                int l=min(50,(int)v.size());
                 for(int i=0;i<l;i++){
                    A[i*2][j]=v[i].second;
                    A[i*2+1][j]=v[i].first;
                }
                for(int i=l*2;i<100;++i){
                    A[i][j]=0; //나머지 0으로 확장
                }
                if(tmpN<(int)v.size()*2){
                    tmpN=(int)v.size()*2;
                }
            }
            n=tmpN;
        }

        if(A[r][c]==k){ //정답 case
            cout<<t<<'\n';
            return 0;
        }
    }

    cout<<-1<<'\n'; //불가능한 case
    return 0;
}
