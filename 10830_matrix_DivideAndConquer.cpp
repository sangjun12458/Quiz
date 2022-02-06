#include <iostream>

using namespace std;

#define DIV_NUM 1000

int N;
long long B;
long long A[5][5];
long long temp[5][5];
long long ans[5][5];

void input()
{
    cin >> N >> B;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];
}
void matrix_mul(long long m1[5][5], long long m2[5][5])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            temp[i][j] = 0;
            for (int k = 0; k < N; k++)
                temp[i][j] += ((m1[i][k] % DIV_NUM) * (m2[k][j] % DIV_NUM));
        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            ans[i][j] = temp[i][j];
}
void pow(long long p)
{
    if (p == 1)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                ans[i][j] = A[i][j];
    else
    {
        pow(p / 2);
        matrix_mul(ans, ans);
        if (p % 2 == 1)
            matrix_mul(ans, A);
    }
}
void print()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << ans[i][j] % DIV_NUM << ' ';
        cout << '\n';
    }
}

int main()
{
    input();
    pow(B);
    print();

    return 0;
}
