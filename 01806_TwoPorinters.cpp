#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
long long S;
int arr[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> arr[i];

    int start = 0;
    int end = 0;
    long long temp = arr[start];
    int ans = INT_MAX;

    while (end < N)
    {
        if (temp >= S)
        {
            ans = min(ans, end - start + 1);
            temp -= arr[start];
            start++;
        }
        else if (temp < S)
        {
            end++;
            temp += arr[end];
        }
    }

    if (ans == INT_MAX) ans = 0;
    cout << ans;

    return 0;
}
