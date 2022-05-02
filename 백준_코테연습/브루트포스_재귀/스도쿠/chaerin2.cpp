//solve void 함수로 풀이

#include <iostream>
using namespace std;

int arr[10][10];
int n=9;
bool check_row[10][10];
bool check_col[10][10];
bool check_box[10][10];

int box (int x, int y){
    return (x/3)*3+(y/3);
}

void solve(int num){
    //정답인 경우
    if(num==81){
        for (int i=0; i<n; i++) {
         for (int j=0; j<n; j++) {
              cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
        exit(0);
    }
    //다음 호출
    int x=num/n;
    int y=num%n;
    if(arr[x][y]){ //숫자 있는 경우
        solve(num+1);
    }
    else{ //숫자 없는 경우
        for (int i=1; i<=9; i++) {
            if (check_row[x][i] == 0 && check_col[y][i] == 0 && check_box[box(x,y)][i]==0) {
                check_row[x][i] = check_col[y][i] = check_box[box(x,y)][i] = true;
                arr[x][y] = i;
                solve(num+1);
                arr[x][y] = 0;
                check_row[x][i] = check_col[y][i] = check_box[box(x,y)][i] = false;
            }
        }       
    }
}



int main () {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    //input 받기
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin >> arr[i][j];
            if(arr[i][j]){
                check_row[i][arr[i][j]]=true;
                check_col[j][arr[i][j]]=true;
                check_box[box(i,j)][arr[i][j]]=true;
            }
        }
    }
    //로직
    solve(0);
 
    return 0;
}
