#include <iostream>

using namespace std;

int n, m, cnt = 0;
int pc[101][101];

void input()
{
    cin >> n >> m;
    while (m--)
    {
        int i, j;
        cin >> i >> j;
        pc[i][j] = 1;
        pc[j][i] = 1;
        pc[i][i] = 1;
        pc[j][j] = 1;
    }
}
void DFS(int node)
{
    pc[node][node] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (pc[node][i] && pc[i][i])
        {
            cnt++;
            pc[node][i] = 0;
            pc[i][node] = 0;
            DFS(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    DFS(1);
    cout << cnt;

    return 0;
}
