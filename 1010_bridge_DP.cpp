#include <iostream>
#define MAX 31
using namespace std;

int t;
int n, m;
int dp[MAX][MAX] = {{0,}};

int main()
{
    cin >> t;
    for (int i = 0; i < MAX; i++) dp[0][i] = 1;
    for (int i = 1; i < MAX; i++)
    {
        for (int j = i; j < MAX; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
        }
    }

    while(t)
    {
        t--;
        cin >> n >> m;
        cout << dp[n][m] << '\n';
    }

    return 0;
}
