#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int H, N, M, cnt = 0, ans = 0;
int box[100][100][100];
int day[100][100][100];
int dh[] = {1, -1, 0, 0, 0, 0};
int dr[] = {0, 0, 0, 0, 1, -1};
int dc[] = {0, 0, -1, 1, 0, 0};
queue<pair<int, pair<int, int>>> q;

void input()
{
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                day[i][j][k] = INT_MAX;

                cin >> box[i][j][k];
                if (box[i][j][k] == 0) cnt++;
                else if (box[i][j][k] == 1)
                {
                    q.push(make_pair(i, make_pair(j, k)));
                    day[i][j][k] = 0;
                }
            }
        }
    }
}
void BFS()
{
    while (!q.empty())
    {
        int h = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nh = h + dh[i];
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nh >= 0 && nh < H && nr >= 0 && nr < N && nc >= 0 && nc < M)
            {
                if (box[nh][nr][nc] == 0)
                {
                    box[nh][nr][nc] = 1;
                    cnt--;
                    day[nh][nr][nc] = min(day[nh][nr][nc], day[h][r][c] + 1);
                    q.push(make_pair(nh, make_pair(nr, nc)));
                    ans = max(ans, day[nh][nr][nc]);
                }
            }
        }
    }
}
void print()
{
    if (cnt == 0) cout << ans;
    else cout << -1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    BFS();
    print();

    return 0;
}
