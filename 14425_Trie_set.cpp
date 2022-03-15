#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int n, m;
set<string> s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    while (n--)
    {
        string str;
        cin >> str;
        s.insert(str);
    }

    int ans = 0;
    while (m--)
    {
        auto size = s.size();

        string str;
        cin >> str;
        s.insert(str);

        if (s.size() == size) ans++;
        else s.erase(str);
    }
    cout << ans;

    return 0;
}
