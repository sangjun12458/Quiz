#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int map[101][101];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
queue<pair<int, int>> q;

void input()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++)
            if (str[j] - '0')
                map[i][j + 1] = 1;
    }
    q.push(make_pair(1, 1));
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
            if (nr > 0 && nr <= N && nc > 0 && nc <= M && map[nr][nc] == 1)
            {
                q.push(make_pair(nr, nc));
                if (map[nr][nc] == 1)
                {
                    map[nr][nc] = map[r][c] + 1;
                }
                else
                {
                    map[nr][nc] = min(map[nr][nc], map[r][c] + 1);
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    BFS();
    cout << map[N][M];

    return 0;
}
