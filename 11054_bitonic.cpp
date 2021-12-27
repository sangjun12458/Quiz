#include <iostream>
#define MAX 1001
using namespace std;

int n;
int arr[MAX];
int DP[MAX];
int increase[MAX];
int diminish[MAX];
int answer = 0;

void Solution()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    DP[0] = 0;
    DP[1] = arr[1];
    increase[1] = diminish[1] = 1;
    int last = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= last; j++)
        {
            if (arr[i] <= DP[j])
            {
                DP[j] = arr[i];
                break;
            }
            if (j == last)
            {
                last++;
                DP[last] = arr[i];
                break;
            }
        }
        increase[i] = last;
    }
    DP[1] = arr[n];
    last = 1;
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= last; j++)
        {
            if (arr[i] <= DP[j])
            {
                DP[j] = arr[i];
                break;
            }
            if (j == last)
            {
                last++;
                DP[last] = arr[i];
                break;
            }
        }
        diminish[i] = last;
    }
    for (int i = 1; i <= n; i++)
    {
        if (increase[i] + diminish[i] - 1 > answer) answer = increase[i] + diminish[i] - 1;
    }
    cout << answer;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solution();
    return 0;
}
