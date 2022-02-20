#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000;
int n, ans_node, ans_dist;
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

    cin >> n;
    int temp = n - 1;
    while (temp--)
    {
        int n1, n2, d;
        cin >> n1 >> n2 >> d;
        tree[n1].push_back(make_pair(n2, d));
        tree[n2].push_back(make_pair(n1, d));
    }

    dfs(1, 0);
    for (int i = 1; i <= n; i++) visited[i] = 0;
    dfs(ans_node, 0);
    cout << ans_dist;

    return 0;
}
