#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10000;
int n;
int costs[MAX + 1];
int DP[2][MAX + 1];
vector<int> graph[MAX + 1];
vector<int> link[2][MAX + 1];

void DFS(int node)
{
    DP[1][node] += costs[node];

    for (int next : graph[node])
    {
        if (DP[1][next] == 0)
        {
            DFS(next);
            if (DP[0][next] > DP[1][next])
            {
                DP[0][node] += DP[0][next];
                for (int temp : link[0][next])
                    link[0][node].push_back(temp);
            }
            else
            {
                DP[0][node] += DP[1][next];
                for (int temp : link[1][next])
                    link[0][node].push_back(temp);
            }
            DP[1][node] += DP[0][next];
            for (int temp : link[0][next])
                    link[1][node].push_back(temp);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> costs[i];
        link[1][i].push_back(i);
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    DFS(1);

    if (DP[0][1] > DP[1][1])
    {
        cout << DP[0][1] << '\n';
        sort(link[0][1].begin(), link[0][1].end());
        for (int temp : link[0][1])
            cout << temp << ' ';
    }
    else
    {
        cout << DP[1][1] << '\n';
        sort(link[1][1].begin(), link[1][1].end());
        for (int temp : link[1][1])
            cout << temp << ' ';
    }

    return 0;
}
