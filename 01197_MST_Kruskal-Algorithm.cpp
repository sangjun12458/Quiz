#include <iostream>
#include <queue>

using namespace std;

int v, e, ans = 0;
int link[10001];
priority_queue<pair<int, pair<int, int>>> pq;

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
    else link[r1] = r2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e;
    for (int i = 1; i <= v; i++)
        link[i] = i;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push(make_pair(-c, make_pair(a, b)));
    }

    while (!pq.empty())
    {
        int n1 = pq.top().second.first;
        int n2 = pq.top().second.second;
        int cost = -pq.top().first;
        pq.pop();

        if (do_find(n1) != do_find(n2))
            ans += cost;
        do_union(n1, n2);
    }
    
    cout << ans;

    return 0;
}
