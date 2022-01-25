#include <iostream>

using namespace std;

long long A, B, C;
long long ans = 1;

void input()
{
    cin >> A >> B >> C;
}
void pow(long long p)
{
    if (p == 1)
        ans = (ans % C) * (A % C);
    else
    {
        pow(p / 2);
        ans = (ans % C) * (ans % C);
        if (p % 2 == 1)
            ans = (ans % C) * (A % C);
    }
}
int main()
{
    input();
    pow(B);
    cout << ans % C;

    return 0;
}
