#include <iostream>
#define MAX 15000

using namespace std;

int w;
int weights[31];
int DP[31][2 * MAX + 1];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> w;
    for (int i = 1; i <= w; i++)
        cin >> weights[i];
    DP[0][MAX] = 1;

    for (int i = 1; i <= w; i++)
    {
        for (int j = 0; j <= 2 * MAX; j++)
            if (DP[i - 1][j - weights[i]] || DP[i - 1][j] || DP[i - 1][j + weights[i]])
                DP[i][j] = 1;
    }

    int m;
    cin >> m;
    while (m--)
    {
        int marble;
        cin >> marble;
        if (marble >= -MAX && marble <= MAX && DP[w][MAX + marble])
            cout << "Y\n";
        else
            cout << "N\n";
    }

    return 0;
}
