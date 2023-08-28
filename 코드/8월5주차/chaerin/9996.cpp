#include <bits/stdc++.h>
using namespace std;

int n;
string pattern,l,r;

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin>>n>>pattern;
    int pos=pattern.find('*');
    l=pattern.substr(0,pos);
    r=pattern.substr(pos+1);

    string input;
    while(n--){
        cin>>input;
        if(input.size()<(pattern.size()-1)) cout<<"NE\n";
        else{
            if(input.substr(0,l.size())==l&&input.substr(input.size() - r.size())==r)
             cout<<"DA\n";
            else cout<<"NE\n";
        }
    }
    
    return 0;
}
