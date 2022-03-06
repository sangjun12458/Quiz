#include <iostream>
#include <cstring>
#include <vector>
#define ll long long

using namespace std;

int n, k;
vector<string> sequence;
vector<int> remainders;
vector<int> digit;
ll dp[40000][100];

ll get_gcd(ll a, ll b)
{
    while (b > 0)
    {
        ll c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        sequence.push_back(str);
    }
    cin >> k;

    for (int i = 0; i < n; i++)
    {
        int r = 0;
        for (int j = 0; j < sequence[i].length(); j++)
        {
            r *= 10;
            r += sequence[i][j] - '0';
            r %= k;
        }
        remainders.push_back(r);
        dp[1 << i][r]++;
    }

    digit.push_back(1 % k);
    for (int i = 0; i < 50; i++)
        digit.push_back(10 * digit[i] % k);

    for (int mask = 1; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) > 0)
                continue;

            int next_bit = mask | (1 << i);

            for (int j = 0; j < k; j++)
            {
                int next_r = (j * digit[sequence[i].length()] + remainders[i]) % k;
                if (dp[mask][j] > 0)
                    dp[next_bit][next_r] += dp[mask][j];
            }
        }
    }

    ll molecule = dp[(1 << n) - 1][0];
    ll denominator = 1;
    for (int i = 2; i <= n; i++)
        denominator *= i;
    ll gcd = get_gcd(denominator, molecule);
    cout << molecule / gcd << '/' << denominator / gcd;

    return 0;
}
