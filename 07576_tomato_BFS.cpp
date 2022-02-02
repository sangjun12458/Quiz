#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int N, M, cnt = 0, ans = 0;
int box[1000][1000];
int day[1000][1000];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
queue<pair<int, int>> q;

void input()
{
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            day[i][j] = INT_MAX;

            cin >> box[i][j];
            if (box[i][j] == 0) cnt++;
            else if (box[i][j] == 1)
            {
                q.push(make_pair(i, j));
                day[i][j] = 0;
            }
        }
    }
}
void BFS()
{
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < N && nc >= 0 && nc < M)
            {
                if (box[nr][nc] == 0)
                {
                    box[nr][nc] = 1;
                    cnt--;
                    day[nr][nc] = min(day[nr][nc], day[r][c] + 1);
                    q.push(make_pair(nr, nc));
                    ans = max(ans, day[nr][nc]);
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
