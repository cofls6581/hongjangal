#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

bool prime[10001];
bool c[10001];
int d[10001];

int change(int num,  int index, int digit){
    if(index==0&&digit==0)
        return -1;
    string s=to_string(num);
    s[index]=digit+'0';
    return stoi(s);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //초기 세팅 소수 배열 세팅
    for (int i = 2; i <= 10000; i++) {
		prime[i] = i;
	}
	for (int i = 2; i <= 10000; i++) {
		if (prime[i] == 0) continue;
		for (int j = i + i; j <= 9999; j += i) {
			prime[j] = 0;
		}
	}
    //input+logic
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin>>n>>m;
        memset(c,false,sizeof(c));
        memset(d,0,sizeof(d));
        d[n]=0; c[n]=true;
        queue<int> q;
        q.push(n);
        while(!q.empty()){
            int now=q.front();
            q.pop();
            for(int i=0;i<4;++i){//자리 위치
                for(int j=0;j<=9;++j){//들어갈 숫자
                    int next=change(now,i,j);
                    if(next!=-1){
                        if(prime[next]&&c[next]==false){
                            q.push(next);
                            d[next]=d[now]+1;
                            c[next]=true;    
                        }
                    }
                }
            }
        } //queue 비었을 때
         //output
         if (c[m] == true) {
			cout << d[m] << '\n';}
		else {
			cout << "Impossible" << '\n';
		}
    }
   
    return 0;
}
