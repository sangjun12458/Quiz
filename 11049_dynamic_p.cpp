#include <iostream>
#include <climits>
#define MAX 501

using namespace std;

int n;
int matrix[MAX][2];
int dp[MAX][MAX];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> matrix[i][0] >> matrix[i][1];

    for (int di = 1; di < n; di++)
    {
        for (int i = 1; i + di <= n; i++)
        {
            dp[i][i + di] = INT_MAX;
            for (int mid = i; mid < i + di; mid++)
            {
                dp[i][i + di] = min(dp[i][i + di], dp[i][mid] + dp[mid + 1][i + di] + matrix[i][0] * matrix[mid][1] * matrix[i + di][1]);
            }
        }
    }

    cout << dp[1][n];

    return 0;
}
