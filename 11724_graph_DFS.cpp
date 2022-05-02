#include <iostream>
#include <vector>

using namespace std;

int n, m, ans = 0;
vector<vector<int>> graph(1001);
bool visited[1001];

void dfs(int n)
{
    if (visited[n])
        return;
    visited[n] = 1;
    for (int next : graph[n])
        dfs(next);
}

int main()
{
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        dfs(i);
        ans++;
    }
    cout << ans;

    return 0;
}
