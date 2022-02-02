#include <iostream>
#include <queue>
#include <climits>
#define MAX 100000

using namespace std;

int N, K;
int point[MAX+1];
int visit[MAX+1];
queue<int> q;

void input()
{
    cin >> N >> K;
    q.push(N);
    visit[N] = 1;
}
void BFS()
{
    while (q.front() != K)
    {
        int x = q.front();
        q.pop();
    
        if (x > 0 && !visit[x-1])
        {
            point[x-1] = point[x]+1;
            q.push(x-1);
            visit[x-1] = 1;
        }
        if (x < MAX && !visit[x+1])
        {
            point[x+1] = point[x]+1;
            q.push(x+1);
            visit[x+1] = 1;
        }
        if (2*x <= MAX && !visit[2*x])
        {
            point[2*x] = point[x]+1;
            q.push(2*x);
            visit[2*x] = 1;
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
    cout << point[K];

    return 0;
}
