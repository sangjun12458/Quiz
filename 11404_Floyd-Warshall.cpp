#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX;
int n, m;
long long graph[101][101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                graph[i][j] = INF;

    while (m--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] == INF) cout << "0 ";
            else cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
