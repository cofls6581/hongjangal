#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

string s;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin>>s;
    bool isOdd=s.size()%2;
    map <char,int> m;
    for(int i=0; i<s.size(); ++i){
        m[s[i]]++;
    }

    char odd;
    bool findOdd=false;
    
    for(auto k: m){
        if((k.second%2)!=0&&findOdd){
            cout<<"I'm Sorry Hansoo\n";
            return 0;
        }
        else if((k.second%2)!=0&&!findOdd){
            if(isOdd){
                odd=k.first;
                findOdd=true;
            }else{
                cout<<"I'm Sorry Hansoo\n";
                return 0;
            }
        }
        else if((k.second)%2==0){
            m[k.first] = k.second/2; 
        }
    }
    if(findOdd){
        if(m[odd]==1) m.erase(odd);
        else{
            m[odd]--;
            m[odd]=m[odd]/2;
        }
    }
    string ans="";
    for(auto k: m){
        for(int i=0; i<k.second; ++i){
            ans+=k.first;
        }
    }
    string ret=ans;
    reverse(ans.begin(),ans.end());
    if(isOdd) ret+=odd;
    ret+=ans;
    cout<<ret<<'\n';
    return 0;
}
