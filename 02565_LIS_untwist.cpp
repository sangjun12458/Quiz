#include <iostream>
#include <algorithm>
#define MAX 501

using namespace std;

int n;
int arr[MAX] = {0,};
int dp[MAX];
int ans = 0;

void Input()
{
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        arr[a] = b;
    }
}
void Solution()
{
    for (int i = 1; i < MAX; i++)
    {
        if (arr[i] != 0)
        {
            dp[i] = 1;
            for (int j = 1; j < i; j++)
            {
                if (arr[j] < arr[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (ans < dp[i]) ans = dp[i];
        }
    }
    cout << n - ans;
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
