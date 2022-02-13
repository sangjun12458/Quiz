#include <iostream>
#include <algorithm>

using namespace std;

int n, x;
int arr[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> x;

    sort(arr, arr + n);

    int start = 0;
    int end = n - 1;
    int cnt = 0;

    while (start < end)
    {
        int temp = arr[start] + arr[end];
        if (temp == x)
        {
            cnt++;
            start++;
            end--;
        }
        else if (temp < x) start++;
        else if (temp > x) end--;
    }

    cout << cnt;

    return 0;
}
