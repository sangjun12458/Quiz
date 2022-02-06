#include <iostream>
#include <vector>

using namespace std;

const int MAX = 20000;

int K, V, E;
vector<int> graph[MAX + 1];
int color[MAX + 1];
bool is_bipartite;

void input()
{
    cin >> V >> E;
    for (int i = 1; i <= V; i++)
    {
        color[i] = 0;
        graph[i].clear();
    }
    while (E--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    is_bipartite = true;
}
void DFS(int start)
{
    if (color[start] == 0) color[start] = 1;

    for (int i = 0; i < graph[start].size(); i++)
    {
        int next = graph[start][i];
        if (color[next] == 0)
        {
            color[next] = 3 - color[start];
            DFS(next);
        }
        else
        {
            if (color[start] == color[next])
            {
                is_bipartite = false;
                return;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;
    while (K--)
    {
        input();
        for (int i = 1; i <= V; i++)
            DFS(i);
        if (is_bipartite) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
