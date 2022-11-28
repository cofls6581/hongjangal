/*
가장 큰 수와 가장 작은 수의 곱이 구하는 정답임을 활용하자.
벡터에서 최대값 최소값을 구하는 문법은 구글링을 통해 알고리즘 헤더파일 문법을 통해 해결했다.
N의 값을 받은 후 이를 활용해 벡테를 선언했는데 전역 변수로 vector <int> n를 선언 후 
cin>>n[i];으로 값을 받을 시에는 정상 작동하지 않는다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input
    cin>>N;
    vector <int> n(N);
    for(int i=0;i<N;++i){
        cin>>n[i];
    }

    //logic
    int minN = *min_element(n.begin(), n.end());
	int maxN = *max_element(n.begin(), n.end());

    //output
    cout<<minN*maxN<<'\n';
    return 0;
}
