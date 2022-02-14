#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int N;
int prime[2001][2001];
int arr[4000001];
vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    for (int i = 2; i <= N; i++)
        arr[i] = i;

    for (int i = 2; i * i <= N; i++)
    {
        if (arr[i] == 0) continue;
        for (int j = i + i; j <= N; j += i)
            arr[j] = 0;
    }

    for (int i = 2; i <= N; i++)
    {
        if (arr[i] != 0)
            v.push_back(i);
    }

    int start = 0;
    int end = 0;
    int temp = 2;
    int cnt = 0;

    while (end < v.size())
    {
        if (temp == N)
        {
            cnt++;
            temp += v[++end];
        }
        else if (temp < N)
        {
            temp += v[++end];
        }
        else
        {
            temp -= v[start++];
        }
    }

    cout << cnt;

    return 0;
}
