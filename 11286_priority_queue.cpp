#include <iostream>
#include <queue>

using namespace std;

template<typename tp>
    struct compare : public binary_function<tp, tp, bool>
    {
        bool operator()(const tp &n1, const tp &n2) const
        {
            if (n1*n1 != n2*n2) return n1*n1 > n2*n2;
            return n1 > n2;
        }
    };

int n;
priority_queue<int, vector<int>, compare<long long>> pq;

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
            if (pq.empty()) cout << "0\n";
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(x);
    }

    return 0;
}
