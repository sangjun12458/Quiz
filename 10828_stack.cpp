#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    stack<int> s;
    string str;
    int a;

    for (int i = 0; i < N; i++)
    {
        cin >> str;
        if (str == "push")
        {
            cin >> a;
            s.push(a);
        }
        else if (str == "size")
        {
            cout << s.size() << endl;
        }
        else if (str == "empty")
        {
            cout << s.empty() ? 1 : 0;
            cout << endl;
        }
        else
        {
            if (s.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << s.top() << endl;
                if (str == "pop") s.pop();
            }
        }
    }

    return 0;
}
