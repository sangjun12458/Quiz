#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int n, k;
class Node
{
private:

public:
    string str;
    map<string, Node> child;

    void set_child(int num)
    {
        if (num == 0) return;
        string s;
        cin >> s;
        child[s].set_child(num - 1);
    }
    void get_child(int num)
    {
        for (auto temp : child)
        {
            for (int i = 0; i < num; i++)
                cout << "--";
            cout << temp.first << '\n';
            temp.second.get_child(num + 1);
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Node root;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        root.set_child(k);
    }

    root.get_child(0);
    
    return 0;
}
