/*
1로만 이루어진 n의 배수의 자릿수 -> 1부터 *10+1활용해 계산하면 되겠구나
input으로 주어지는 테스트 케이스의 수가 유동적인 거 주의-> 구글링 통해 while문 사용하기로 결정
원래는 k=1로 초기화 후 for문의 int i=2로 초기화해 사용했는데 이렇게 되면 1인 경우는 처리가 안돼 수정함.
*/

#include <iostream>
using namespace std;

int N;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
   
    while(cin>>N) {
       int k=0;
       for (int i = 1; i<=N ;++i) {
            k = k * 10 + 1;
            k %= N;
            if (k == 0) {
                cout<<i<<'\n';
                break;
            }
        }
    }

    return 0;
}
