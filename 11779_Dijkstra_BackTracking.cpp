#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

const int INF = INT_MAX;
const int MAX = 1000;
int n, m, A, B;
int dist[MAX + 1];
int idx[MAX + 1]; 
vector<pair<int, int>> graph[MAX + 1];

void input()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }
    cin >> A >> B;
    for (int i = 1; i <= n; i++) dist[i] = INF;
}
void solution()
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, A));

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].first;
            int ncost = graph[cur][i].second;

            if (dist[next] > cost + ncost)
            {
                dist[next] = cost + ncost;
                idx[next] = cur;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }

    stack<int> ans;
    ans.push(B);
    while (ans.top() != A)
    {
        ans.push(idx[ans.top()]);
    }
    cout << dist[B] << '\n'
         << ans.size() << '\n';
    while (!ans.empty())
    {
        cout << ans.top() << ' ';
        ans.pop();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solution();

    return 0;
}
