#include <iostream>
#define MAX 2001

using namespace std;

int N, M;
int seq[MAX];
int DP[MAX][MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> seq[i];

    for (int di = 0; di < N; di++)
    {
        for (int i = 1; i + di <= N; i++)
        {
            int j = i + di;

            if (di < 2) DP[i][j] = 1;
            else DP[i][j] = DP[i + 1][j - 1];

            if (seq[i] != seq[j]) DP[i][j] = 0;
        }
    }

    cin >> M;
    while (M--)
    {
        int S, E;
        cin >> S >> E;

        cout << DP[S][E] << '\n';
    }

    return 0;
} 
