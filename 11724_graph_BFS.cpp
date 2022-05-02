#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, ans = 0;
vector<vector<int>> graph(1001);
bool visited[1001];
queue<int> q;

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
        
        q.push(i);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            visited[cur] = 1;

            for (int next : graph[cur])
            {
                if (!visited[next])
                    q.push(next);
                graph[cur].pop_back();
            }
        }

        ans++;
    }
    cout << ans;

    return 0;
}
