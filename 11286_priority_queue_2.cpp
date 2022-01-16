#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq1;
priority_queue<int> pq2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            if (pq1.empty() && pq2.empty()) cout << "0\n";
            else
            {
                if (pq1.empty()) { cout << pq2.top() << '\n'; pq2.pop(); }
                else if (pq2.empty()) { cout << pq1.top() << '\n'; pq1.pop(); }
                else
                {
                    if (pq1.top() >= -pq2.top()) { cout << pq2.top() << '\n'; pq2.pop(); }
                    else { cout << pq1.top() << '\n'; pq1.pop(); }
                }
            }
        }
        else if (x > 0) pq1.push(x);
        else pq2.push(x);
    }

    return 0;
}
