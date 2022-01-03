#include <iostream>

using namespace std;

int t;

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;
        int _n = 2, _m = m - n + 1;
        int ans = 1;
        while (1)
        {
            if (_m <= m) ans *= _m;
            _m++;
            if (_n <= n && ans % _n == 0)
            {
                ans /= _n;
                _n++;
            }
            if (_n > n && _m > m) break;
        }
        cout << ans << '\n';
    } 

    return 0;
}
