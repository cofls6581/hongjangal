
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int ans = -1;
bool broken[11];

int check(int n)
{
    if (n == 0)
    {
        if (broken[0])
            return 0;
        else
            return 1;
    }

    int numberPress = 0;
    while (n > 0)
    {
        if (broken[n % 10])
            return 0;
        n /= 10;
        numberPress++;
    }
    return numberPress;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    // input
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        broken[x] = true;
    }
    // logic
    int ans = n - 100; //+,-버튼만 사용할 때, 문제에서 100번부터 시작
    if (ans < 0) //100미만 수 
        ans = -ans;

    for (int i = 0; i < 10000001; i++)
    {
        int c = i;
        int numberPress = check(c);
        if (numberPress > 0)
        {
            int plusMinuspress = abs(c - n);
            if (ans > plusMinuspress + numberPress)
            {
                ans = plusMinuspress + numberPress;
            }
        }
    }
    // output
    cout << ans << endl;
    return 0;
}
