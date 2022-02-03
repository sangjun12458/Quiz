#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    int arr[1000000];
    int nge[1000000];
    stack<int> s;

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int i = N - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
        {
            s.pop();
        }
        if (s.empty()) nge[i] = -1;
        else nge[i] = s.top();
        s.push(arr[i]);
    }

    for (int i = 0; i < N; i++) cout << nge[i] << ' ';

    return 0;
}
