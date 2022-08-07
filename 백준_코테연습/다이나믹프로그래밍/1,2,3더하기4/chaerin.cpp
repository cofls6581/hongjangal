#include <iostream>
using namespace std;

int d[100001];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
     d[0] = 1;
    for (int i=1; i<=100000; i++) { //마지막 1
        if (i-1 >= 0) {
            d[i] += d[i-1];
        }
    }
    for (int i=1; i<=100000; i++) { //마지막 2
        if (i-2 >= 0) {
            d[i] += d[i-2];
        }
    }
    for (int i=1; i<=100000; i++) { //마지막 3
        if (i-3 >= 0) {
            d[i] += d[i-3];
        }
    }

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<d[n]<<'\n';
    }

    return 0;
}
