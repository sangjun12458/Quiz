#include <iostream>

using namespace std;

int n, ans;
int cnt_2 = 0, cnt_5 = 0;

void Divisor(int x, int y)
{
    if (x % y == 0)
    {
        if (y == 2) cnt_2++;
        else cnt_5++;
        Divisor(x / y, y);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        Divisor(i, 2);
        Divisor(i, 5);
    }
    ans = cnt_2;
    if (ans > cnt_5) ans = cnt_5;
    cout << ans;

    return 0;
}
