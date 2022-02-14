#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int arr[100000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr + N);

    int start = 0;
    int end = N - 1;
    int a1;
    int a2;
    int a3 = INT_MAX;

    while (start < end)
    {
        int temp = arr[start] + arr[end];
        if (a3 > temp && a3 > -temp)
        {
            a1 = arr[start];
            a2 = arr[end];
            a3 = max(temp, -temp);
        }
        if (temp < 0)
            start++;
        else
            end--;
    }

    cout << a1 << ' ' << a2;

    return 0;
}
