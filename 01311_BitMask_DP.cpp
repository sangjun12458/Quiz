#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

const int INF = INT_MAX;
int n;
int cost[21][21];
int dp[1100000];

int count_bits(int b)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (b == (b | (1 << i))) cnt++;
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    int max = pow(2, n);
    dp[0] = 0;
    for (int i = 1; i < max; i++)
        dp[i] = INF;

    for (int mask = 0; mask < max; mask++)
    {
        int x = count_bits(mask);
        for (int i = 0; i < n; i++)
            dp[mask|(1<<i)] = min(dp[mask|(1<<i)], dp[mask] + cost[x][i]);
    }

    cout << dp[max - 1];

    return 0;
}
