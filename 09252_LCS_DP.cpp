#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

string a, b;
int dp[1001][1001];
pair<int, int> idx[1001][1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> a >> b;

    for (int i = 0; i < a.length(); i++)
    {
        for (int j = 0; j < b.length(); j++)
        {
            dp[i + 1][j + 1] = dp[i][j + 1];
            idx[i + 1][j + 1] = make_pair(i, j + 1);
            if (dp[i + 1][j + 1] < dp[i + 1][j])
            {
                dp[i + 1][j + 1] = dp[i + 1][j];
                idx[i + 1][j + 1] = make_pair(i + 1, j);
            }
            if (a[i] == b[j] && dp[i + 1][j + 1] < dp[i][j] + 1)
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                idx[i + 1][j + 1] = make_pair(i, j);
            }
        }
    }

    vector<char> v;
    int row = a.length();
    int col = b.length();
    while (row != 0 && col != 0)
    {
        int nrow = idx[row][col].first;
        int ncol = idx[row][col].second;
        if (row == nrow + 1 && col == ncol + 1)
            v.push_back(a[row - 1]);
        row = nrow;
        col = ncol;
    }

    cout << v.size() << '\n';
    for (int i = v.size() - 1; i >= 0; i--)
        cout << v[i];

    return 0; 
}
