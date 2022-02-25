#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define P pair<int, int>
#define X first.second
#define Y second.first
#define Z second.second

using namespace std;

int n;
int link[100000];
vector<pair<P, P>> v;
priority_queue<pair<int, P>> pq;

bool compare_x(pair<P, P> p1, pair<P, P> p2)
{ return p1.X > p2.X; }
bool compare_y(pair<P, P> p1, pair<P, P> p2)
{ return p1.Y > p2.Y; }
bool compare_z(pair<P, P> p1, pair<P, P> p2)
{ return p1.Z > p2.Z; }
int do_find(int node)
{
    if (link[node] == node) return node;
    return link[node] = do_find(link[node]);
}
void do_union(int n1, int n2)
{
    int r1 = do_find(n1);
    int r2 = do_find(n2);
    if (r1 < r2) link[r2] = r1;
    else link[r1] = r2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back(make_pair(make_pair(i, x), make_pair(y, z)));
        link[i] = i;
    }

    sort(v.begin(), v.end(), compare_x);
    for (int i = 1; i < n; i++)
    {
        int p1 = v[i - 1].first.first;
        int p2 = v[i].first.first;
        int cost = v[i - 1].X - v[i].X;
        pq.push(make_pair(-cost, make_pair(p1, p2)));
    }
    sort(v.begin(), v.end(), compare_y);
    for (int i = 1; i < n; i++)
    {
        int p1 = v[i - 1].first.first;
        int p2 = v[i].first.first;
        int cost = v[i - 1].Y - v[i].Y;
        pq.push(make_pair(-cost, make_pair(p1, p2)));
    }
    sort(v.begin(), v.end(), compare_z);
    for (int i = 1; i < n; i++)
    {
        int p1 = v[i - 1].first.first;
        int p2 = v[i].first.first;
        int cost = v[i - 1].Z - v[i].Z;
        pq.push(make_pair(-cost, make_pair(p1, p2)));
    }

    long long ans = 0;
    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int p1 = pq.top().second.first;
        int p2 = pq.top().second.second;
        pq.pop();

        if (do_find(p1) != do_find(p2))
            ans += cost;
        do_union(p1, p2);
    }
    cout << ans;

    return 0;
}
