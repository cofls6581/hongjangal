#include <bits/stdc++.h>
using namespace std;

int n;
int score[3];
int ans[3]={0,};
int team; string s;

int main (){
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin>>n;
    score[1]=score[2]=0;
    int beforeScoreTime=0;
    int currentTime=0;
    while(n--){ 
        cin>>team; cin>>s;
        int m=stoi(s.substr(0, 2));
        int ss=stoi(s.substr(3, 2));
        currentTime=m*60+ss;

        if(score[1]>score[2]){
            ans[1]+=currentTime-beforeScoreTime;
        }
        else if(score[1]<score[2]){
            ans[2]+=currentTime-beforeScoreTime;
        }

        if(team==1) score[1]++;
        else score[2]++;

        beforeScoreTime=currentTime;
    }

    currentTime=48*60;
    if(score[1]>score[2]){
        ans[1]+=currentTime-beforeScoreTime;
    }
    else if(score[1]<score[2]){
        ans[2]+=currentTime-beforeScoreTime;
    }

    string ansM,ansS;
    ansM="00"+to_string(ans[1]/60);
    ansS="00"+to_string(ans[1]%60);
    cout<<ansM.substr(ansM.size()-2,2)<<':'<<ansS.substr(ansS.size()-2,2)<<'\n';

    ansM="00"+to_string(ans[2]/60);
    ansS="00"+to_string(ans[2]%60);
    cout<<ansM.substr(ansM.size()-2,2)<<':'<<ansS.substr(ansS.size()-2,2)<<'\n';
    
    return 0;
}
