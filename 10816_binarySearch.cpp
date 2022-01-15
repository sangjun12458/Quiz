#include <iostream>
#include <algorithm>
#define MAX 500000

using namespace std;

int n, m;
int my[MAX], arr[MAX];

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> my[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> arr[i];
}

int main()
{
    input();
    sort(my, my + n);
    
    for (int i = 0; i < m; i++)
    {
        int x = 1;
        int y = 0;

        int start = 0;
        int end = n - 1;
        
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (arr[i] == my[mid]) {
                x = mid;
                end = mid - 1;
            } else if (arr[i] < my[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        start = 0;
        end = n - 1;
        
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (arr[i] == my[mid]) {
                y = mid;
                start = mid + 1;
            } else if (arr[i] < my[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        cout << y - x + 1 << '\n';
    }

    return 0;
}
