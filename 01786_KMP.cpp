#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

string t, p;
vector<int> ans;

vector<int> get_pi()
{
    int m = p.length(), j = 0;
    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++)
    {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}
void kmp()
{
    vector<int> pi = get_pi();
    int n = t.length();
    int m = p.length();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j > 0 && t[i] != p[j])
            j = pi[j - 1];
        if (t[i] == p[j])
        {
            if (j == m - 1)
            {
                ans.push_back(i - m + 1);
                j = pi[j];
            }
            else
                j++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    getline(cin, t);
    getline(cin, p);
    kmp();
    cout << (int)ans.size() << '\n';
    for (int temp : ans)
        cout << temp + 1 << ' ';
    
    return 0;
}
