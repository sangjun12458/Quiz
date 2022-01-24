#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n, m;
int sum = 0;
int ans = INT_MAX;
int memory[101];
int cost[101];
long long DP[101][10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> memory[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        sum += cost[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j < cost[i]) DP[i][j] = DP[i - 1][j];
            else DP[i][j] = max(DP[i - 1][j - cost[i]] + memory[i], DP[i - 1][j]);
        }
    }

    for (int i = 0; i <= sum; i++) if (DP[n][i] >= m) ans = min(ans, i);
    cout << ans;

    return 0;
}
