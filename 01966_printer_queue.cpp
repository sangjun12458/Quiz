#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(int a, int b) { return a > b; }

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;

        int arr[100];
        int ans[100];
        queue<int> q;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            ans[i] = arr[i];
            q.push(i);
        }

        sort(ans, ans + n, compare);

        for (int i = 0; i < n; i++) {
            while (arr[q.front()] != ans[i])
            {
                q.push(q.front());
                q.pop();
            }
            ans[i] = q.front();
            q.pop();
        }
        
        for (int i = 0; i < n; i++) {
            if (ans[i] == m) cout << i + 1 << '\n';
        }
    }

    return 0;
}
