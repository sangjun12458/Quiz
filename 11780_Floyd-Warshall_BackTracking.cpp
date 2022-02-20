#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = INT_MAX;
const int MAX = 100;
int n, m;
long long bus[MAX + 1][MAX + 1];
vector<int>previous[MAX + 1][MAX + 1];

void solution()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                bus[i][j] = INF;
                previous[i][j].push_back(i);
                previous[i][j].push_back(j);
            }
        }
    }

    while (m--)
    {
        int v1, v2;
        long long c;
        cin >> v1 >> v2 >> c;
        if (bus[v1][v2] > c)
        {
            bus[v1][v2] = c;
        }
    }
    for (int mid = 1; mid <= n; mid++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (mid == i) continue;
            for (int j = 1; j <= n; j++)
            {
                if (mid == j || i == j) continue;
                if (bus[i][j] > bus[i][mid] + bus[mid][j])
                {
                    bus[i][j] = bus[i][mid] + bus[mid][j];

                    while (!previous[i][j].empty()) previous[i][j].pop_back();
                    for (int k = 0; k < previous[i][mid].size(); k++)
                        previous[i][j].push_back(previous[i][mid][k]);
                    previous[i][j].pop_back();
                    for (int k = 0; k < previous[mid][j].size(); k++)
                        previous[i][j].push_back(previous[mid][j][k]);
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {   
            if (bus[i][j] == INF)
            {
                cout << "0 ";
                continue;
            }
            cout << bus[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j || bus[i][j] == INF)
            {
                cout << "0\n";
                continue;
            }
            cout << previous[i][j].size() << ' ';
            for (int k = 0; k < previous[i][j].size(); k++)
                cout << previous[i][j][k] << ' ';
            cout << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    solution();

    return 0;
}
