/*
범위가 1 ≤ T ≤ 100,000, 1 ≤ N ≤ 1,000,000인 것을 확인하고 
최적화 방안을 고민함.
매 테스트케이스마다 g(n)을 처음부터 구하지 않고 다이나믹프로그래밍 개념을 활용해
각 배열의 인덱스에 해당하는 g(index) 값을 미리 다 계산해 저장해둠.
필요시 해당 인덱스의 값만 읽어 출력하는 방식을 사용함.
*/

#include <iostream>
using namespace std;

#define MAX 1000001

int t;
long long dp[MAX];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input
    cin >> t;

    //logic
    for(int i = 1; i < MAX; i++){
        for(int j = i; j < MAX; j+=i){
            dp[j] += i;
        }
    }
    for(int i = 2; i < MAX; i++){
        dp[i] += dp[i-1];
    }

    //output
    int temp;
    while (t--) {
        cin>>temp;
        cout<<dp[temp]<<'\n';
    }

    return 0;
}
