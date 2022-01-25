#include <iostream>
#include <queue>

using namespace std;

int n, m, v;
int graph1[1001][1001];
int graph2[1001][1001];
queue<int> q;

void input()
{
    cin >> n >> m >> v;
    while (m--)
    {
        int s, e;
        cin >> s >> e;
        graph1[s][e] = 1;
        graph2[s][e] = 1;
        graph1[e][s] = 1;
        graph2[e][s] = 1; 
    }
}
void DFS(int node)
{
    cout << node << ' ';
    graph1[node][node] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (node != i && graph1[node][i] && !graph1[i][i])
        {
            graph1[node][i] = 0;
            graph1[i][node] = 0;
            DFS(i);
        }
    }
}
void BFS(int node)
{
    q.push(node);
    while (!q.empty())
    {
        node = q.front();
        cout << node << ' ';
        for (int i = 1; i <= n; i++)
        {
            if (graph2[node][i] && !graph2[i][i])
            {
                q.push(i);
                graph2[node][i] = 0;
                graph2[i][node] = 0;
                graph2[i][i] = 1;
            }
        }
        q.pop();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    DFS(v);
    cout << '\n';
    BFS(v);

    return 0;
}
