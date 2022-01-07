#include <iostream>

using namespace std;

class Deque
{
    private:
    int f = 10000;
    int b = 9999;
    int arr[20000];

    public:
    void push_front(int x);
    void push_back(int x);
    void pop_front();
    void pop_back();
    void size();
    void empty();
    void front();
    void back();
};
void Deque::push_front(int x) { arr[--f] = x; }
void Deque::push_back(int x) { arr[++b] = x; }
void Deque::pop_front() {
    if (f <= b) cout << arr[f++] << '\n';
    else cout << -1 << '\n';
}
void Deque::pop_back() {
    if (f <= b) cout << arr[b--] << '\n';
    else cout << -1 << '\n';
}
void Deque::size() { cout << b - f + 1 << '\n'; }
void Deque::empty() {
    if (f > b) cout << 1 << '\n';
    else cout << 0 << '\n';
}
void Deque::front() {
    if (f <= b) cout << arr[f] << '\n';
    else cout << -1 << '\n';
}
void Deque::back() {
    if (f <= b) cout << arr[b] << '\n';
    else cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    Deque d;
    string str;

    while(n--) {
        cin >> str;
        if (str == "push_front") { int a; cin >> a; d.push_front(a); }
        else if (str == "push_back") { int a; cin >> a; d.push_back(a); }
        else if (str == "pop_front") { d.pop_front(); }
        else if (str == "pop_back") { d.pop_back(); }
        else if (str == "size") { d.size(); }
        else if (str == "empty") { d.empty(); }
        else if (str == "front") { d.front(); }
        else if (str == "back") { d.back(); }
    }

    return 0;
}
