#include <iostream>
#include <algorithm>
#define MAX 10000

using namespace std;

int k;
long long n;
int arr[MAX];
int ans;

int main()
{
    cin >> k >> n;
    for (int i = 0; i < k; i++)
        cin >> arr[i];
    sort(arr, arr + k);

    long long min = 1;
    long long max = arr[k - 1];
    
    while (min <= max)
    {
        long long mid = (min + max) / 2;
        long long sum = 0;

        for (int i = 0; i < k; i++)
            sum += (arr[i] / mid);

        if (sum >= n)
        {
            ans = mid;
            min = mid + 1;
        }
        else
            max = mid - 1;
    }

    cout << ans;

    return 0;
}
