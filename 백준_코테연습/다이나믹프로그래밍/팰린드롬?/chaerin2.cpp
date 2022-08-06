#include <iostream>
#include <cstring>
using namespace std;

bool d[2000][2000];
int a[2000];
int n,m;

void dp() {
    for (int i=0; i<n-1; i++) {
        if (a[i] == a[i+1]) {
            d[i][i+1] = true;
        }
    }
    for (int k=3; k<=n; k++) {
        for (int i=0; i<=n-k; i++) {
            int j = i+k-1;
            if (a[i] == a[j] && d[i+1][j-1]) {
                d[i][j] = true;
            }
        }
    }

}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>a[i]; 
        d[i][i]=true;
    }
    dp();
    cin>>m;
    while(m--){
        int i,j;
        cin>>i>>j;
        cout<<d[i-1][j-1]<<'\n';
    }
    return 0;
}
