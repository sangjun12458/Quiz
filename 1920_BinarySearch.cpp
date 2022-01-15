#include <iostream>
#include <algorithm>
#define MAX 100000

using namespace std;

int n, m;
int a[MAX], b[MAX];

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i];
}

int main()
{
    input();
    sort(a, a + n);
    for (int i = 0; i < m; i++)
    {
        int start = 0;
        int end = n - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (b[i] == a[mid])
            {
                cout << 1 << '\n';
                break;
            }
            else if (b[i] < a[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        if (start > end)
        {
            cout << 0 << '\n';
        }
    }

    return 0;
}
