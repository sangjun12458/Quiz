#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 800;
int N, E, v1, v2;
vector<pair<int, int>> graph[MAX + 1];
int dist[MAX + 1];

void input()
{
    cin >> N >> E;
    while (E--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    cin >> v1 >> v2;
}
void reset()
{
    for (int i = 1; i <= N; i++) dist[i] = INT_MAX;
}
void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i].first;
            int ncost = graph[current][i].second;

            if (dist[next] > cost + ncost)
            {
                dist[next] = cost + ncost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
}
void solution()
{
    int r1, r2, r3, r4, r5, ans = INT_MAX;
    
    reset();
    dijkstra(1);
    r1 = dist[v1];
    r2 = dist[v2];

    reset();
    dijkstra(v1);
    r3 = dist[v2];
    r4 = dist[N];

    reset();
    dijkstra(v2);
    r5 = dist[N];

    if (r1 != INT_MAX)
    {
        ans = r1 + r3 + r5;
    }
    if (r2 != INT_MAX)
    {
        ans = min(ans, r2 + r3 + r4);
    }
    
    if (ans == INT_MAX) ans = -1;
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solution();

    return 0;
}
