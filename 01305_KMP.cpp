#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int l;
    string str;
    cin >> l >> str;
    int n = str.length();

    vector<int> pi(l, 0);
    int j = 0;
    for (int i = 1; i < l; i++)
    {
        while (j > 0 && str[j] != str[i])
            j = pi[j - 1];
        if (str[j] == str[i])
            pi[i] = ++j;
    }

    cout << l - pi[l - 1];

    return 0;
}
