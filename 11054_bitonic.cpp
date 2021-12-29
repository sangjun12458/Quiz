#include <iostream>
#include <algorithm>
#define MAX 1000

using namespace std;

int n;
int arr[MAX];
int dp[MAX];
int ans;

void Input()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
}

void Solution()
{
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    ans = dp[0];
    for (int i = 1; i < n; i++)
    {
        if (ans < dp[i]) ans = dp[i];
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();

    return 0;
}
