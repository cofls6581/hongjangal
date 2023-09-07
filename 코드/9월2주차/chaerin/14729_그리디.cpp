#include <iostream>
#include <queue>
using namespace std;

int n;

int main(){
    ios::sync_with_stdio(0); cin.tie(NULL);

    cin>>n; 

    double score;
    priority_queue <double,vector<double>, greater<double>> pq;

    while(n--){
        cin>>score;
        pq.push(score);
    }

    for(int i=0; i<7; ++i){
        cout<<fixed;
        cout.precision(3);
        //cout.unsetf(ios::fixed);
        cout<<(double)pq.top()<<'\n';
        pq.pop();
    }

    return 0;
}
