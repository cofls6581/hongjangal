/*
처음에는 Input을 받은 후 바로 소수 판별 로직을 짜려고 했다가
소수 구하는 로직들을 활용해 소수인지아닌지 정보를 저장하는 배열을 미리 세팅한뒤
인풋을 받아 해당 인풋이 소수인지아닌지 배열의 값을 읽어와 판별하는 방식으로 로직 수정.
*/


#include <iostream>
using namespace std;

int N,num;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input
    cin>>N;

    //logic 
    int ans=0;
    while(N--){
        bool isPrime=true;
        cin>>num;
        if(num==1) isPrime=false;
        for(int i=2; i*i<=num; i++)
            if(num%i==0) isPrime=false;
        if(isPrime==true) ans++;
    }
    
    //output
    cout<<ans<<'\n';
    return 0;
}
