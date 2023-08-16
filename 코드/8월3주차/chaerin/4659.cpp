#include <bits/stdc++.h>
using namespace std;

int main () {
    ios::sync_with_stdio(0); cin.tie(NULL);

    string s;
    while(true){
        cin>>s;
        if(s=="end") break;

        bool c1=false;
        bool flag=false;
        pair<int,int> p={-1,-1};
        char before;

        for(int i=0; i<s.size();++i){
            bool m=false;
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){ //조건 1
                m=true; c1=true;
            }
            
            if(i==0){ 
                if(m) p={0,1}; //모음
                else p={1,1}; //자음
            }
            else{
                if(m){ //모음
                    if(p.first==0){ //이전 모음
                        if(p.second==2) {
                            flag=true;
                            break;
                        } 
                        p.second=p.second+1;
                    }
                    else p={0,1}; //이전 자음
                }
                else{ //자음
                    if(p.first==1){ //이전 자음
                        if(p.second==2) {
                            flag=true;
                            break;
                        }
                        p.second=p.second+1;
                    }
                    else p={1,1}; //이전 모음
                }
            }

            if(before==s[i]&&s[i]!='e'&&s[i]!='o'){ //조건 3
                flag=true;
                break;
            }
            before=s[i];
        }

        if(!c1) flag=true;
        if(!flag) cout<<'<'<<s<<"> is acceptable."<<'\n';
        else cout<<'<'<<s<<"> is not acceptable."<<'\n';
        before='\n'; p={-1,-1};
    }

    return 0;
}
