#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
#include <stack>

using namespace std;

const int INF = INT_MAX;
const int MAX = 10000;
int T;

int func_D(int num)
{
    num *= 2;
    if (num >= MAX)
        num %= MAX;
    return num;
}
int func_S(int num)
{
    if (num == 0)
        return 9999;
    return num - 1;
}
int func_L(int num)
{
    int d1, d2, d3, d4;
    d1 = num / 1000;
    d2 = num / 100 % 10;
    d3 = num / 10 % 10;
    d4 = num % 10;
    return d2 * 1000 + d3 * 100 + d4 * 10 + d1;
}
int func_R(int num)
{
    int d1, d2, d3, d4;
    d1 = num / 1000;
    d2 = num / 100 % 10;
    d3 = num / 10 % 10;
    d4 = num % 10;
    return d4 * 1000 + d1 * 100 + d2 * 10 + d3;
}
void solution(int a, int b)
{
    pair<int, pair<int, string>> DP[MAX];
    for (int i = 0; i < MAX; i++)
        DP[i].first = INF;
    DP[a].first = 0;
    queue<int> q;
    q.push(a);

    while (q.front() != b)
    {
        int x = q.front();
        q.pop();
        int y;
        y = func_D(x);
        if (DP[y].first > DP[x].first + 1)
        {
            DP[y].first = DP[x].first + 1;
            DP[y].second.first = x;
            DP[y].second.second = 'D';
            q.push(y);
        }
        y = func_S(x);
        if (DP[y].first > DP[x].first + 1)
        {
            DP[y].first = DP[x].first + 1;
            DP[y].second.first = x;
            DP[y].second.second = 'S';
            q.push(y);
        }
        y = func_L(x);
        if (DP[y].first > DP[x].first + 1)
        {
            DP[y].first = DP[x].first + 1;
            DP[y].second.first = x;
            DP[y].second.second = 'L';
            q.push(y);
        }
        y = func_R(x);
        if (DP[y].first > DP[x].first + 1)
        {
            DP[y].first = DP[x].first + 1;
            DP[y].second.first = x;
            DP[y].second.second = 'R';
            q.push(y);
        }
    }

    stack<int> ans;
    ans.push(b);
    int temp = b;
    while(temp != a)
    {
        ans.push(DP[temp].second.first);
        temp = DP[temp].second.first;
    }
    while (!ans.empty())
    {
        cout << DP[ans.top()].second.second;
        ans.pop();
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while (T--)
    {
        int A, B;
        cin >> A >> B;
        solution(A, B);
    }

    return 0;
}
