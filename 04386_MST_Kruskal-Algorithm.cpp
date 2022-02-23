#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int n;
int link[101];
vector<pair<float, float>> v; //점의 좌표
priority_queue<pair<float, pair<int, int>>> pq; //두점과 거리

float calculate(int a, int b) //거리 계산
{
    float dx = v[a].first - v[b].first;
    float dy = v[a].second - v[b].second;
    return sqrt(pow(dx, 2) + pow(dy, 2));
}
int do_find(int node) //점의 루트 찾기
{
    if (link[node] == node) return node;
    return link[node] = do_find(link[node]);
}
void do_union(int n1, int n2) //두 점을 잇기
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
        link[i] = i;

    for (int i = 0; i < n; i++)
    {
        float x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            pq.push(make_pair(-calculate(i, j), make_pair(i, j)));

    float ans = 0;
    while (!pq.empty())
    {
        int p1 = pq.top().second.first;
        int p2 = pq.top().second.second;
        float dist = -pq.top().first;
        pq.pop();

        if (do_find(p1) != do_find(p2)) ans += dist;
        do_union(p1, p2);
    }

    cout << fixed;
    cout.precision(2);
    cout << ans;

    return 0;
}
