#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num; 
        
        if (i % 2 == 0) pq1.push(num);
        else pq2.push(num);

        if (!pq2.empty())
        {
            while (pq1.top() > pq2.top())
            {
                pq1.push(pq2.top());
                pq2.pop();
                pq2.push(pq1.top());
                pq1.pop();
            }
        }

        cout << pq1.top() << '\n';
    }

    return 0;
}
