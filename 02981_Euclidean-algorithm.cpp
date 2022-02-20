#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A, B, C;

int gcd(int a, int b)
{
    int u = max(a, b);
    int d = min(a, b);
    a = u;
    b = d;
    while (b > 0)
    {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int arr[100];
    
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);

    int temp = arr[1] - arr[0];
    for (int i = 2; i < N; i++)
    {
        temp = gcd(temp, arr[i] - arr[i - 1]);
    }

    vector<int> ans;
    ans.push_back(temp);
    for (int i = 2; i * i <= temp; i++)
    {
        if (temp % i == 0)
        {
            ans.push_back(i);
            if (i != temp / i)
                ans.push_back(temp / i);
        }
    }
    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';

    return 0;
}
