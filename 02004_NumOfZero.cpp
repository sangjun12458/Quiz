#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int cnt;

void Divisor(int a, int b)
{
    cnt = 0;
    while (a / b != 0)
    {
        cnt += a / b;
        a /= b;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    Divisor(n, 2);
    int cnt_2 = cnt;
    Divisor(n, 5);
    int cnt_5 = cnt;
    Divisor(m, 2);
    cnt_2 -= cnt;
    Divisor(m, 5);
    cnt_5 -= cnt;
    Divisor(n - m, 2);
    cnt_2 -= cnt;
    Divisor(n - m, 5);
    cnt_5 -= cnt;

    cout << min(cnt_2, cnt_5);

    return 0;
}
