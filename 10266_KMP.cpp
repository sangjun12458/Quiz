#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 360000;
int n;
int angles[200000];
string str1, str2;

string input()
{
    string str;

    for (int i = 0; i < n; i++)
        cin >> angles[i];
    sort(angles, angles + n);

    for (int i = 1; i < n; i++)
        str += to_string(angles[i] - angles[i - 1]);
    str += to_string(MAX + angles[0] - angles[n - 1]);

    return str;
}
vector<int> get_pi()
{
    int l = str2.length();
    vector<int> pi(l, 0);

    int j = 0;
    for (int i = 1; i < l; i++)
    {
        while (j > 0 && str2[j] != str2[i])
            j = pi[j - 1];
        if (str2[j] == str2[i])
            pi[i] = ++j;
    }

    return pi;
}
bool kmp()
{
    vector<int> pi = get_pi();
    int l1 = str1.length();
    int l2 = str2.length();

    int j = 0;
    for (int i = 0; i < l1; i++)
    {
        while (j > 0 && str2[j] != str1[i])
            j = pi[j - 1];
        if (str2[j] == str1[i])
        {
            if (j == l2 - 1)
                return 1;
            j++;
        }
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    str1 = input();
    str2 = input();
    str1 += str1;
    
    if (kmp())
        cout << "possible";
    else
        cout << "impossible";

    return 0;
}
