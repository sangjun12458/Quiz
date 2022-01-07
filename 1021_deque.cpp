#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[m];
    for (int i = 0; i < m; i++) cin >> arr[i];

    deque<int> d;
    for (int i = 1; i <= n; i++) d.push_back(i);

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int temp = 0;
        while (d.front() != arr[i]) {
            d.push_back(d.front());
            d.pop_front();
            temp++;
        }
        if (temp > d.size() - temp) temp = d.size() - temp;
        d.pop_front();
        ans += temp;
    }

    cout << ans;

    return 0;
}
