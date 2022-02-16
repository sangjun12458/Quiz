#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[1001];
int DP[1001];
vector<int> LIS;
vector<int> idx;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    LIS.push_back(0);
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

        for (int j = 1; j < LIS.size(); j++)
        {
            if (LIS[j - 1] < arr[i] && LIS[j] >= arr[i])
            {
                LIS[j] = arr[i];
                idx[j] = i;
                DP[i] = idx[j - 1];
            }
        }
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
    {
        cout << ans[i] << ' ';
    }

    return 0; 
}
