#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int n, m;
int link[1001];
vector<pair<int, int>> v;
priority_queue<pair<double, pair<int, int>>> pq;

double calculate(int a, int b)
{
    long long dx = v[a].first - v[b].first;
    long long dy = v[a].second - v[b].second;
    dx = pow(dx, 2);
    dy = pow(dy, 2);
    return sqrt(dx + dy);
}
int do_find(int n)
{
    if (link[n] == n) return n;
    return link[n] = do_find(link[n]);
}
void do_union(int n1, int n2)
{
    int r1 = do_find(n1);
    int r2 = do_find(n2);
    if (r1 < r2) link[r2] = r1;
    else if (r1 > r2) link[r1] = r2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        link[i] = i;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        do_union(a - 1, b - 1);
    }

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            pq.push(make_pair(-calculate(i, j), make_pair(i, j)));

    double ans = 0;
    while (!pq.empty())
    {
        int p1 = pq.top().second.first;
        int p2 = pq.top().second.second;
        double dist = -pq.top().first;
        pq.pop();

        if (do_find(p1) != do_find(p2)) ans += dist;
        do_union(p1, p2);
    }
    
    cout << fixed;
    cout.precision(2);
    cout << ans;

    return 0;
}
