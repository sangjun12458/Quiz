#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 1001

using namespace std;

int dp[MAX][MAX] = {{0,},};
char ch1[MAX], ch2[MAX];

void Solve()
{
    cin >> ch1 >> ch2;

    for (int i = 0; i < strlen(ch1); i++)
    {
        for (int j = 0; j < strlen(ch2); j++)
        {
            if (ch1[i] == ch2[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    cout << dp[strlen(ch1)][strlen(ch2)];
}

int main()
{
    Solve();
    return 0;
}
