#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;
int V, E;
long long graph[401][401];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    while (E--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++)
            if (!graph[i][j]) graph[i][j] = INF;

    for (int mid = 1; mid <= V; mid++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                graph[i][j] = min(graph[i][j], graph[i][mid] + graph[mid][j]);
    
    long long ans = INF;
    for (int i = 1; i <= V; i++)
        ans = min(ans, graph[i][i]);

    if (ans == INF) cout << -1;
    else cout << ans;

    return 0;
}
