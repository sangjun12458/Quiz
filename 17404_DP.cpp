#include <iostream>

using namespace std;

const int MAX = 1000 * 1000 + 1;
int n;
int cost[1000][3];
int dp[1000][3];
int ans = MAX;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> cost[i][j];
    
    for (int i = 0; i < 3; i++)
    {
        dp[0][i] = cost[0][i];

        dp[1][i] = MAX;
        dp[1][(i + 1) % 3] = dp[0][i] + cost[1][(i + 1) % 3];
        dp[1][(i + 2) % 3] = dp[0][i] + cost[1][(i + 2) % 3];

        for (int j = 2; j < n; j++)
        {
            dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + cost[j][0];
            dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + cost[j][1];
            dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + cost[j][2];
        }

        int temp = min(dp[n - 1][(i + 1) % 3], dp[n - 1][(i + 2) % 3]);
        ans = min(ans, temp);
    }
    
    cout << ans;

    return 0;
}
