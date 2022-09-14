#include <iostream>
#include <vector>
using namespace std;

int n;
long long d[100][21];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    //로직
    d[0][a[0]] = 1;
    for (int i=1; i<n-1; i++) {
        for (int j=0; j<21; j++) {
            if(j-a[i]>=0){
                d[i][j] += d[i-1][j-a[i]];
            }
            if(j+a[i] <= 20){
                d[i][j] += d[i-1][j+a[i]];
            }
        }
    }
    //output
    cout << d[n-2][a[n-1]] << '\n';
    return 0;
}
