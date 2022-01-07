#include <iostream>
#define MAX 2000000
using namespace std;

class Queue
{
    private:
    int f = 0;
    int b = -1;
    int arr[MAX];

    public:
    void push(int x);
    void pop();
    void size();
    void empty();
    void front();
    void back();
};
void Queue::push(int x) { arr[++b] = x; }
void Queue::pop() { 
    if (f <= b) cout << arr[f++] << '\n';
    else cout << -1 << '\n';
}
void Queue::size() { cout << b - f + 1 << '\n'; }
void Queue::empty() { 
    if (f > b) cout << 1 << '\n'; 
    else cout << 0 << '\n';
}
void Queue::front() {
    if (f <= b) cout << arr[f] << '\n';
    else cout << -1 << '\n';
}
void Queue::back() {
    if (f <= b) cout << arr[b] << '\n';
    else cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Queue q;
    string str;
    int n;
    cin >> n;

    while(n--) {
        cin >> str;
        if (str == "push") {
            int a;
            cin >> a;
            q.push(a);
        }
        else if (str == "pop") { q.pop(); }
        else if (str == "size") { q.size(); }
        else if (str == "empty") { q.empty(); }
        else if (str == "front") { q.front(); }
        else if (str == "back") { q.back(); }
    }

    return 0;
}
