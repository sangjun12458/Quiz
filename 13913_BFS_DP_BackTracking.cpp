#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;
const int MAX = 100000;
int N, K;
int DP[MAX + 1];
int point[MAX + 1];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i <= MAX; i++) DP[i] = INF;
    DP[N] = 0;

    queue<int> q;
    q.push(N);

    while (q.front() != K)
    {
        int cur = q.front();
        q.pop();
        if (cur > 0 && DP[cur - 1] > DP[cur] + 1)
        {
            DP[cur - 1] = DP[cur] + 1;
            q.push(cur - 1);
            point[cur - 1] = cur;
        }
        if (cur < MAX && DP[cur + 1] > DP[cur] + 1)
        {
            DP[cur + 1] = DP[cur] + 1;
            q.push(cur + 1);
            point[cur + 1] = cur;
        }
        if (2 * cur <= MAX && DP[2 * cur] > DP[cur] + 1)
        {
            DP[2 * cur] = DP[cur] + 1;
            q.push(2 * cur);
            point[2 * cur] = cur;
        }
    }

    
    vector<int> ans;
    ans.push_back(K);
    int temp = K;
    while (temp != N)
    {
        ans.push_back(point[temp]);
        temp = point[temp];
    }

    cout << ans.size() - 1 << '\n';
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << ' ';

    return 0;
}
