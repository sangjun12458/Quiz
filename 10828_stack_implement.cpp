#include <iostream>
using namespace std;

class Stack
{
private:
    int t = -1;
    int arr[100000];

public:
    Stack(){};
    void push(int x);
    void pop();
    void size();
    void empty();
    void top();
};
void Stack::push(int x) { arr[++t] = x; }
void Stack::pop()
{
    if (t == -1) cout << -1 << '\n';
    else cout << arr[t--] << '\n';
}
void Stack::size() { cout << t + 1 << '\n'; }
void Stack::empty()
{
    if (t == -1)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
}
void Stack::top()
{
    if (t == -1)
        cout << -1 << '\n';
    else
        cout << arr[t] << '\n';
}
int main()
{
    Stack s;
    int n;
    cin >> n;

    string ch;
    int a;

    while (n--)
    {
        cin >> ch;
        if (ch == "push")
        {
            cin >> a;
            s.push(a);
        }
        else if (ch == "pop") s.pop();
        else if (ch == "size") s.size();
        else if (ch == "empty") s.empty();
        else if (ch == "top") s.top();
    }

    return 0;
}
