#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000;
int V, ans_node, ans_dist;
bool visited[MAX + 1];
vector<pair<int, int>> tree[MAX + 1];

void dfs(int cur, int dist)
{
    visited[cur] = 1;
    for (int i = 0; i < tree[cur].size(); i++)
    {
        int next = tree[cur][i].first;
        int ndist = tree[cur][i].second;
        if (!visited[next])
        {
            if (ans_dist < dist + ndist)
            {
                ans_dist = dist + ndist;
                ans_node = next;
            }
            dfs(next, dist + ndist);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V;
    int temp = V;
    while (temp--)
    {
        int i, j, d;
        cin >> i;
        while (1)
        {
            cin >> j;
            if (j == -1)
                break;
            cin >> d;
            tree[i].push_back(make_pair(j, d));
        }
    }

    dfs(1, 0);
    for (int i = 1; i <= V; i++) visited[i] = 0;
    dfs(ans_node, 0);
    cout << ans_dist;

    return 0;
}
