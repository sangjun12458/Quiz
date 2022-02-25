#include <iostream>
#include <vector>
#include <queue>
#define P pair<int, int>

using namespace std;

int n, m;
int map[100][100];
P link[100][100];
vector<pair<P, P>> v;
priority_queue<pair<int, pair<P, P>>> pq;

P do_find(P node)
{
    if (link[node.first][node.second] == node)
        return node;
    return link[node.first][node.second] = do_find(link[node.first][node.second]);
}
void do_union(P n1, P n2)
{
    P r1 = do_find(n1);
    P r2 = do_find(n2);
    if (r1.first <= r2.first && r1.second <= r2.second)
        link[r2.first][r2.second] = r1;
    else
        link[r1.first][r1.second] = r2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            link[i][j] = make_pair(i, j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        vector<P> temp;
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
                continue;
            temp.push_back(link[i][j]);
        }
        for (int j = 1; j < temp.size(); j++)
        {
            P p1 = temp[j - 1];
            P p2 = temp[j];
            int dist = p2.second - p1.second - 1;
            pq.push(make_pair(-dist, make_pair(p1, p2)));
        }
    }
    for (int j = 0; j < m; j++)
    {
        vector<P> temp;
        for (int i = 0; i < n; i++)
        {
            if (map[i][j] == 0)
                continue;
            temp.push_back(link[i][j]);
        }
        for (int i = 1; i < temp.size(); i++)
        {
            P p1 = temp[i - 1];
            P p2 = temp[i];
            int dist = p2.first - p1.first - 1;
            pq.push(make_pair(-dist, make_pair(p1, p2)));
        }
    }

    long long ans = 0;
    while (!pq.empty())
    {
        int dist = -pq.top().first;
        P p1 = pq.top().second.first;
        P p2 = pq.top().second.second;
        pq.pop();

        if (do_find(p1) != do_find(p2))
        {
            if (dist == 0)
                do_union(p1, p2);
            else if (dist == 1)
                continue;
            else
            {
                ans += dist;
                do_union(p1, p2);
            }
        }
    }

    P root = pair(-1, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0) continue;
            if (root == pair(-1, -1)) root = do_find(pair(i, j));
            if (root != do_find(pair(i, j))) ans = -1;
        }
    }
    cout << ans;

    return 0;
}
