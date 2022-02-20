#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 26;
int N;
pair<int, int> tree[MAX];

void preT(int node)
{
    if (node == -1) return;
    cout << (char)(node + 'A');
    preT(tree[node].first);
    preT(tree[node].second);
}
void inT(int node)
{
    if (node == -1) return;
    inT(tree[node].first);
    cout << (char)(node + 'A');
    inT(tree[node].second);
}
void postT(int node)
{
    if (node == -1) return;
    postT(tree[node].first);
    postT(tree[node].second);
    cout << (char)(node + 'A');
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char str, l, r;
        cin >> str >> l >> r;

        tree[str - 'A'].first = -1;
        tree[str - 'A'].second = -1;
        if (l != '.') tree[str - 'A'].first = l - 'A';
        if (r != '.') tree[str - 'A'].second = r - 'A';
    }
    preT(0);
    cout << '\n';
    inT(0);
    cout << '\n';
    postT(0);

    return 0;
}
