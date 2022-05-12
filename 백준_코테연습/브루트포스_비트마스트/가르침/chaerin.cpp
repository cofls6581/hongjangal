#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n,k;

int getNum(int mask, vector <int> &words){
    int num=0;
    for(int word : words){
        if((word&((1<<26)-1-mask))==0){
            num++;
        }
    }
    return num;
}

int solve(int idx, int left, int mask, vector<int>&words){
    if(left<0) //정답 불가능한 케이스, 더 이상 알파벳 뽑기 불가
        return 0;
    if(idx==26){ // 정답인 케이스
        return getNum(mask,words);
    }
    int ans=0;
    int temp=solve(idx+1,left-1,mask|(1<<idx),words); //현재 인덱스 알파벳 넣는 경우 
    if(ans<temp) 
        ans=temp;
    if(idx!='a'-'a'&&idx!='n'-'a'&&idx!='t'-'a'&&idx!='i'-'a'&&idx!='c'-'a'){
        temp=solve(idx+1,left,mask,words); //현재 인덱스 알파벳 안넣는 경우
        if(ans<temp) 
            ans=temp;
    }

    return ans;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    cin>>n>>k;
    vector<int> words(n);
    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        //단어에 존재하는 알파벳 비트마스크로 1 처리
        for(char c:s){
            words[i] |= (1 << (c-'a')) ;
        }
    }

    //로직+output
    cout<<solve(0,k,0,words)<<'\n';
    
    return 0;
}
