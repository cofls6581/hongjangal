#include <bits/stdc++.h>
using namespace std;

int n;
queue <int> q;
int fav[402][4]={0,};
int arr[402][402]={0,};

pair<int,int> locate;
int favN,emptyN;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    
    //input 
    cin>>n;
    int tmp;
    for(int i=0;i<n*n;++i){
        cin>>tmp;
        q.push(tmp);
        for(int j=0;j<4;++j){
            cin>>fav[tmp][j];
        }
    }

    //logic
    int current;
    while(q.size()){
        current=q.front(); q.pop();
        favN=emptyN=-1;
        for(int i=0;i<n;++i){ //행
            for(int j=0;j<n;++j){ //열
                int eTemp=0; int fTemp=0;
                if(arr[i][j]>0) continue;
                for(int k=0;k<4;++k){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx<0||nx>=n||ny<0||ny>=n) continue;
                    if(arr[nx][ny]==0) eTemp++;
                    if((arr[nx][ny]==fav[current][0])||(arr[nx][ny]==fav[current][1])||(arr[nx][ny]==fav[current][2])||(arr[nx][ny]==fav[current][3])){
                        fTemp++;
                    }
                }
                if(fTemp>favN){
                    favN=fTemp;
                    emptyN=eTemp;
                    locate=make_pair(i,j);
                }
                else if(fTemp==favN){
                    if(emptyN<eTemp){
                        emptyN=eTemp;
                        locate=make_pair(i,j);
                    }
                }
            }
        }
        arr[locate.first][locate.second]=current;
    }

    //output
    int ans=0;
    for(int i=0;i<n;++i){ //행
        for(int j=0;j<n;++j){ //열
            favN=0;
            current=arr[i][j];
            for(int k=0;k<4;++k){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx<0||nx>=n||ny<0||ny>=n) continue;
                if((arr[nx][ny]==fav[current][0])||(arr[nx][ny]==fav[current][1])||(arr[nx][ny]==fav[current][2])||(arr[nx][ny]==fav[current][3]))
                    favN++;
            }
            if(favN!=0)  ans+=pow(10,(favN-1));
        }
    }
    cout<<ans<<'\n';

    return 0;
}
