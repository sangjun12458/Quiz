#include <iostream>
#include <vector>
#define MAX 1000000

using namespace std;

int n;
int arr[MAX];
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    v.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (v.back() < arr[i])
        {
            v.push_back(arr[i]);
        }
        else
        {
            int start = 0;
            int end = v.size() - 1;
            int temp = end + 1;
            while (start <= end)
            {
                int mid = (start + end) / 2;
                if (v[mid] < arr[i])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                    temp = mid;
                }
            }
            v[temp] = arr[i];
        }
    }
    cout << v.size();

    return 0;
}
