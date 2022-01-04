#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> k;

    stack<int> s;
    int temp;
    
    while(k--)
    {
        cin >> temp;
        if (temp != 0) s.push(temp);
        else s.pop();
    }

    int ans = 0;
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        ans += s.top();
        s.pop();
    }

    cout << ans;

    return 0;
}
