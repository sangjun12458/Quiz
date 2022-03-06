#include <iostream>

using namespace std;

const int DIV_NUM = 1000000003;
int n, k;
long long dp[1001][3];
long long ans = 0;

void print()
{
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        for (int j = 0; j < 3; j++)
            cout << dp[i][j] << ' ';
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    
    for (int i = 0; i < 2; i++)
    {
        for (int i = 0; i <= k; i++)
            dp[i][0] = dp[i][1] = dp[i][2] = 0;

        if (!i)
            dp[0][0] = dp[0][2] = dp[1][1] = 1;
        else
            dp[1][0] = 1;

        int t = n - 1;

        while (--t)
        {
            for (int j = 0; j <= k; j++)
                dp[j][2] = (dp[j][0] + dp[j][1]) % DIV_NUM;
            for (int j = 0; j < k; j++)
                dp[j + 1][1] = dp[j][0];
            for (int j = 0; j <= k; j++)
                dp[j][0] = dp[j][2];
        }

        ans += dp[k][0] % DIV_NUM;
        if (!i)
            ans += dp[k][1] % DIV_NUM;

    }

    cout << ans % DIV_NUM;

    return 0;
}
