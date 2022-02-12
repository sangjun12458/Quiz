#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;
const int MAX = 2000;
int T, n, m, t, s, g, h;
vector<pair<int, int>> map[MAX + 1];
int dist[MAX + 1];
int des[4][MAX + 1];
int gtoh;

void input()
{
    cin >> n >> m >> t >> s >> g >> h;
    while (m--)
    {
        int a, b, d;
        cin >> a >> b >> d;
        map[a].push_back(make_pair(b, d));
        map[b].push_back(make_pair(a, d));
        if ((a == g && b == h) || (a == h && b == g))
            gtoh = d;
    }
    while (t--)
    {
        int x;
        cin >> x;
        des[0][x] = INF;
    }
}
void dijkstra(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        for (int i = 0; i < map[current].size(); i++)
        {
            int next = map[current][i].first;
            int ncost = map[current][i].second;

            if (dist[next] > cost + ncost)
            {
                dist[next] = cost + ncost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
}
void reset(int start)
{
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[start] = 0;
}
void solution()
{
    reset(s);
    dijkstra(s);
    for (int i = 1; i <= n; i++)
        if (i == g || i == h || des[0][i] == INF)
            des[1][i] = dist[i];

    reset(g);
    dijkstra(g);
    for (int i = 1; i <= n; i++)
        if (des[0][i] == INF)
            des[2][i] = dist[i];

    reset(h);
    dijkstra(h);
    for (int i = 1; i <= n; i++)
        if (des[0][i] == INF)
            des[3][i] = dist[i];

    for (int i = 1; i <= n; i++)
        if (des[0][i] == INF)
            if (des[1][i] == des[1][g] + gtoh + des[3][i] || des[1][i] == des[1][h] + gtoh + des[2][i])
                cout << i << ' ';
}
void solve()
{
    cin >> T;
    while (T--)
    {
        for (int i = 1; i <= n; i++)
            while (!map[i].empty())
                map[i].pop_back();
        for (int i = 0; i < 4; i++)
            for (int j = 1; j <= n; j++)
                des[i][j] = 0;
        input();
        solution();
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
