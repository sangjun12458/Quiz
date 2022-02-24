#include <iostream>
#include <vector>
#include <queue>
#define P pair<int, int>

using namespace std;

int v, e;
long long ans = 0;
bool visited[10001];
vector<P> graph[10001];

void prim()
{
    priority_queue<P> pq;
    pq.push(P(0, 1));

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (visited[cur])
            continue;
        visited[cur] = 1;
        ans += cost;

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].second;
            int ncost = graph[cur][i].first;
            if (!visited[next])
                pq.push(P(-ncost, next));
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(P(c, b));
        graph[b].push_back(P(c, a));
    }

    prim();
    cout << ans;

    return 0;
}
