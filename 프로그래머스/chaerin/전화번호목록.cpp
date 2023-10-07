//hash 
#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> pb) {
    bool answer = true;
    sort(pb.begin(),pb.end());
    set <string> phoneNum;
    
    for(int i=0; i<pb.size(); ++i){
        phoneNum.insert(pb[i]);
    }
    
    for(int i=0; i<pb.size(); ++i){
        for(int j=1; j<pb[i].size();++j){
            if(phoneNum.find(pb[i].substr(0,j))!=phoneNum.end()){
                answer=false;
                return answer;
            }        
        }
    }
    return answer;
}
