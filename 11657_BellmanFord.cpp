#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX;
const int MAX = 500;
int N, M;
long long dist[MAX + 1];
vector<pair<int, int>> graph[MAX + 1];

void input()
{
    cin >> N >> M;
    while (M--)
    {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back(make_pair(B, C));
    }
    for (int i = 2; i <= N; i++)
        dist[i] = INF;
}
void solution()
{
    int repeat = N - 1;
    while (repeat--)
    {
        for (int i = 1; i <= N; i++)
        {
            if (dist[i] == INF)
                continue;
            
            for (int j = 0; j < graph[i].size(); j++)
            {
                int next = graph[i][j].first;
                int ncost = graph[i][j].second;
                dist[next] = min(dist[next], dist[i] + ncost);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (dist[i] == INF)
            continue;

        for (int j = 0; j < graph[i].size(); j++)
        {
            int next = graph[i][j].first;
            int ncost = graph[i][j].second;
            if (dist[next] > dist[i] + ncost)
            {
                cout << -1;
                return;
            }
        }
    }

    for (int i = 2; i <= N; i++)
    {
        if (dist[i] == INF)
            cout << -1 << '\n';
        else
            cout << dist[i] << '\n';
    }
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
