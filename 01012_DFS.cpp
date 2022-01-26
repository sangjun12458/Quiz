#include <iostream>
#define MAX 50

using namespace std;

int T, M, N, K, cnt;
int map[MAX][MAX];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

void input()
{
    cin >> M >> N >> K;
    while (K--)
    {
        int X, Y;
        cin >> X >> Y;
        map[Y][X] = 1;
    }
}
void DFS(int r, int c)
{
    if (!map[r][c]) return;
    map[r][c] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        DFS(nr, nc);
    }
}
void Solve()
{
    cin >> T;
    while (T--)
    {
        input();
        cnt = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (map[i][j])
                {
                    DFS(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;
}
