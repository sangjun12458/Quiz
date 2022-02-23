#include <iostream>

using namespace std;

const int MAX = 500000;
int n, m;
int tree[MAX];

int do_find(int x)
{
    if (tree[x] == x) return x;
    return tree[x] = do_find(tree[x]);
}
void do_union(int n1, int n2)
{
    int s1 = do_find(n1);
    int s2 = do_find(n2);
    if (s1 < s2) tree[s2] = s1;
    else if (s1 > s2) tree[s1] = s2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < n; i++)
        tree[i] = i;

    for (int i = 1; i <= m; i++)
    {
        int p1, p2;
        cin >> p1 >> p2;

        if (do_find(p1) == do_find(p2))
            if (ans == 0)
                ans = i;

        do_union(p1, p2);
    }
    cout << ans;

    return 0;
}
