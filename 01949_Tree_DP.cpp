#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10000;
int N;
int people[MAX + 1];
int excellent[2][MAX + 1];
vector<int> graph[MAX + 1];

void DFS(int n1)
{
    excellent[1][n1] = people[n1];
    for (int n2 : graph[n1])
    {
        if (excellent[1][n2] != 0) continue;
        DFS(n2);
        excellent[0][n1] += max(excellent[0][n2], excellent[1][n2]);
        excellent[1][n1] += excellent[0][n2];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> people[i];
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    DFS(1);
    cout << max(excellent[0][1], excellent[1][1]);

    return 0;
}
