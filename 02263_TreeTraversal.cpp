#include <iostream>

using namespace std;

const int MAX = 100000;
int n;
int inorder[MAX + 1];
int postorder[MAX + 1];
int idx[MAX + 1];
int visited[MAX + 1];
pair<int, int> tree[MAX + 1];

void search(int in_s, int in_e, int post_s, int post_e)
{
    if (in_s > in_e || post_s > post_e) return;
    int root = postorder[post_e];
    int in_mid = idx[root];
    int in_left = in_mid - in_s;
    int in_right = in_e - in_mid;
    if (!visited[postorder[post_e - in_right - 1]])
    {
        tree[root].first = postorder[post_e - in_right - 1];
        visited[postorder[post_e - in_right - 1]] = true;
    }
    if (!visited[postorder[post_e - 1]]) 
    {
        tree[root].second = postorder[post_e - 1];
        visited[postorder[post_e - 1]] = true;
    }
    search(in_s, in_mid - 1, post_s, post_e - in_right - 1);
    search(in_mid + 1, in_e, post_e - in_right, post_e - 1);
}
void traverse_pre(int node)
{
    if (node == 0) return;
    cout << node << ' ';
    traverse_pre(tree[node].first);
    traverse_pre(tree[node].second);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> inorder[i];
    for (int i = 1; i <= n; i++)
        cin >> postorder[i];
    for (int i = 1; i <= n; i++)
        idx[inorder[i]] = i;
    
    search(1, n, 1, n);
    traverse_pre(postorder[n]);

    return 0;
}
