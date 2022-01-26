#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 30

using namespace std;

int N, cnt = 0;
int map[MAX][MAX];
int AC[MAX * MAX];
int dr[] = {0, 0, 1, -1};
int dc[] = {-1, 1, 0, 0};

void input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++)
            if (str[j] - '0')
                map[i][j + 1] = 1;
    }
}
void DFS(int r, int c)
{
    if (map[r][c] == 0)
        return;

    map[r][c] = 0;
    AC[cnt]++;
    for (int i = 0; i < 4; i++)
        DFS(r + dr[i], c + dc[i]);
}
void Solve()
{
    input();
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (map[i][j] == 1)
            {
                DFS(i, j);
                cnt++;
            }
        }
    }
    sort(AC, AC + cnt);
    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++)
        cout << AC[i] << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;
}
