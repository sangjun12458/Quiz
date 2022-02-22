#include <iostream>
#include <vector>

using namespace std;

const int MAX = 200;
int n, m;
int route[MAX + 1];
vector<int> plan;

int do_find(int n)
{
    if (n == route[n])
        return n;
    return route[n] = do_find(route[n]);
}
void do_union(int n1, int n2)
{
    int s1 = do_find(n1);
    int s2 = do_find(n2);

    if (s1 > s2)
        route[s2] = s1;
    else if (s1 < s2)
        route[s1] = s2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        route[i] = i;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int t;
            cin >> t;
            if (t)
                do_union(i, j);
        }
    }
    int a;
    while (cin >> a)
        plan.push_back(a);

    int is_route = true;
    for (int i = 1; i < plan.size(); i++)
    {
        if (do_find(plan[i - 1]) != do_find(plan[i]))
            is_route = false;
    }

    if (is_route)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
