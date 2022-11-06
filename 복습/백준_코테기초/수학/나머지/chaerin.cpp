/* 제일 처음엔 인풋을 다 배열에 저장 후 다시 전체 순회를 하며 나머지 값을 계산하는 로직을 생각했다가
생각해보니 배열에 저장안하고 그때그때 나머지 값을 계산해 나머지 값만 저장하면 되는 로직이라 해당 방식으로 품.
distinct한 나머지 값을 세야하는 문제로 모든 나머지 값이 다 정답에 영향을 끼치지 않아 유동적인 값으로 보여
벡터를 활용하면 좋을 것 같아 나머지 값을 담는 용도로 벡터를 사용함.
*/

#include <iostream>
#include <vector>
using namespace std;

int num;
vector <int> ans;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    for(int i=0;i<10;++i){
        cin >>num;
        int temp=num%42;
        int isExist=false;
        for(int j=0;j<ans.size();j++){
            if(ans[j]==temp)
             isExist=true;
        }
        if(!isExist){
            ans.push_back(temp);
        }
    }

    cout << ans.size() << '\n';
    return 0;
}
