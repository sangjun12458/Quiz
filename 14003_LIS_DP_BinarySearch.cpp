#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
int arr[1000001];
int DP[1000001];
vector<int> LIS;
vector<int> idx;

void BS(int num, int s, int e)
{
    int mid = (s + e) / 2;
    if (LIS[mid] < arr[num] && LIS[mid + 1] >= arr[num])
    {
        LIS[mid + 1] = arr[num];
        idx[mid + 1] = num;
        DP[num] = idx[mid];
    }
    else if (LIS[mid] < arr[num] && LIS[mid + 1] < arr[num])
        BS(num, mid + 1, e);
    else if (LIS[mid] >= arr[num] && LIS[mid + 1] >= arr[num])
        BS(num, s, mid - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    LIS.push_back(INT_MIN);
    idx.push_back(0);
    DP[0] = 0;

    for (int i = 1; i <= N; i++)
    {
        if (LIS.back() < arr[i])
        {
            DP[i] = idx.back();
            LIS.push_back(arr[i]);
            idx.push_back(i);
            continue;
        }
        BS(i, 0, LIS.size() - 1);
    }

    vector<int> ans;
    int temp = idx[LIS.size() - 1];
    while (temp != 0)
    {
        ans.push_back(arr[temp]);
        temp = DP[temp];
    }

    cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << ' ';

    return 0; 
}
