#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, s1, s2, e1, e2;
    int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int board[300][300];
    queue<pair<int, int>> q;
    cin >> t;

    while (t--)
    {
        while (!q.empty()) q.pop();
        cin >> n >> s1 >> s2 >> e1 >> e2;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) board[i][j] = 0;
        q.push(make_pair(s1, s2));
    
        while (q.front().first != e1 || q.front().second != e2)
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 8; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc] == 0)
                {
                    board[nr][nc] = board[r][c] + 1;
                    q.push(make_pair(nr, nc));
                }
            }
        }
        cout << board[e1][e2] << '\n';
    }
}
