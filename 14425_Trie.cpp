#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int n, m;
map<string, int> root;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        root[str] = 1;
    }

    int ans = 0;
    while (m--)
    {
        string str;
        cin >> str;
        auto temp = root.find(str);
        if (temp->second == 1) ans++;
    }
    cout << ans;

    return 0;
}
