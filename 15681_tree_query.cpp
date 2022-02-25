#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;
int n, r, q;
int link[MAX];
int cnt[MAX];
vector<int> graph[MAX];

int DFS(int n1)
{
    for (int n2 : graph[n1])
    {
        if (link[n2] != 0) continue;
        link[n2] = n1;
        cnt[n1] += DFS(n2);
    }
    cnt[n1]++;
    return cnt[n1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> r >> q;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    link[r] = r;
    cnt[r] = DFS(r);

    while (q--)
    {
        int temp;
        cin >> temp; 
        cout << cnt[temp] << '\n';
    }
 
    return 0;
}
