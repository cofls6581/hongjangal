#include <bits/stdc++.h>
using namespace std;

int n; 

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n; 
    int k=665; 

    while(k++){
        if(to_string(k).find("666") != string::npos)
            n--; 
        if(n==0) break;
    }
    
    cout << k << "\n"; 

    return 0;
}
