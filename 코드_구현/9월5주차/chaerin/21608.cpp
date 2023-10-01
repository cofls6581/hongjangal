#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector <int> v[401];
int score[]={0,1,10,100,1000};
int arr[21][21]={0,};
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

struct student {
	int x, y, blankN=0, favN = 0;
    bool operator <(const student& i) const{
        if(favN!=i.favN) return favN<i.favN;
        if(blankN!=i.blankN) return blankN<i.blankN;
        if(x!=i.x) return x>i.x;
        return y>i.y;
    }
};

void put(int num){
    priority_queue<student> pq;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(arr[i][j]!=0) continue;
            int fN=0, bN=0;
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                for (int l = 0; l < 4; ++l) {
                    if (arr[nx][ny] == v[num][l]) fN++;
                }
                if (arr[nx][ny]==0) bN++;
            }
            pq.push({ i,j,bN,fN });
        }
    }
    arr[pq.top().x][pq.top().y]=num;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n;
    int k,l;
    for(int i=0; i<(n*n); ++i){
        cin>>k;
        for(int j=0; j<4; ++j){
            cin>>l;
            v[k].push_back(l);
        }
        put(k);
    }

    int res=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int tmp=0;
            int cur=arr[i][j];
            for(int k=0; k<4;++k){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                for (int l = 0; l < 4; ++l) {
                    if (arr[nx][ny] == v[cur][l]) tmp++;
                }
            }
            res+=score[tmp];
        }
    }
    cout<<res<<'\n';

    return 0;
}
