/*
행 교환
    1. arr[i][j]와 arr[i][j + 1]을 교환
    2. 가장 긴 행이나 열 체크
    3. 1번 원복

열 교환
    1. arr[i][j]와 arr[i + 1][j]을 교환
    2. 가장 긴 행이나 열 체크
    3. 1번 원복

동적할당 받는 방식 사용했다가 check 함수 사용을 위한 전역 변수 사용을 위해 char block[50][50];로 변경함.
char **block = new char *[n]; // 2차원 배열 동적할당
    for (int i = 0; i < n; i++)
        block[i] = new char[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> block[i][j];
        }
    }

*/

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int ans = 0;
char block[50][50];

void check() //가장 긴 행 또는 열 확인하는 함수
{

    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        for (int j = 0; j < n; j++)
        {
            if (block[i][j] == block[i][j + 1])
            {
                cnt++;
            }
            else
            {
                if (ans < cnt)
                {
                    ans = cnt;
                }
                cnt = 1;
            }
        }
    }

    for (int j = 0; j < n; j++)
    {
        int cnt = 1;
        for (int i = 0; i < n; i++)
        {
            if (block[i][j] == block[i + 1][j])
            {
                cnt++;
            }
            else
            {
                if (ans < cnt)
                {
                    ans = cnt;
                }
                cnt = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // input
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> block[i][j];
        }
    }

    // logic
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            swap(block[i][j], block[i][j + 1]);
            check();
            swap(block[i][j], block[i][j + 1]); //원복
        }
    }

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            swap(block[i][j], block[i + 1][j]);
            check();
            swap(block[i][j], block[i + 1][j]); //원복
        }
    }

    // output
    cout << ans << endl;

    return 0;
}
