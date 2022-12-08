/*
범위가 6 ≤ n ≤ 1000000이고 메모리 제한이 지난 번에 풀었던 문제와 동일하게 256MB인 것을 보고
bool 자료형을 쓰기로 결정했다.
*/

#include <iostream>
#define max 1000000 
using namespace std;

int n;
bool isPrime[max + 1] = {false, };

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    //input
	isPrime[1]=true;

	for (int i = 2; i <= max; ++i) {
		if (!isPrime[i]) {
			for (int j = i+i ; j <= max ; j+=i)
				isPrime[j] = true;
		}
	}
    
    //logic+output
    bool isExist=false;
    
    while (1) { 
		cin >> n;
		if (n == 0) break;
		for (int i = 2; i <= n/2; i++) {
			if ((isPrime[i] == false) && (isPrime[n - i] == false)) {
				cout << n << " = " << i << " + " << (n - i)<<'\n';
                isExist=true;
				break;
			}
		}
	}

    if(!isExist){
        cout<<"Goldbach's conjecture is wrong."<<'\n';
    }

    return 0;
}
