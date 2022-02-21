#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;
vector<int> preorder;
pair<int, int> tree[MAX + 1];
bool visited[MAX + 1];

void search(int node, int root)
{
    if (node < root)
    {
        if (tree[root].first == 0) tree[root].first = node;
        else search(node, tree[root].first);
    }
    else if (node > root)
    {
        if (tree[root].second == 0) tree[root].second = node;
        else search(node, tree[root].second);
    }
}
void traverse_post(int node)
{
    if (node == 0 || visited[node]) return;
    visited[node] = true;
    traverse_post(tree[node].first);
    traverse_post(tree[node].second);
    cout << node << '\n'; 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    while (cin >> num)
        preorder.push_back(num);

    for (int i = 1; i < preorder.size(); i++)
        search(preorder[i], preorder[0]);

    traverse_post(preorder[0]);

    return 0;
}
