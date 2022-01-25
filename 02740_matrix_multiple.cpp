#include <iostream>

using namespace std;

int A[100][100];
int B[100][100];
int N, M, K;
int AB[100][100] = {{0,}};

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> A[i][j];
    }
    cin >> M >> K;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) cin >> B[i][j];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < M; k++) {
                AB[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) cout << AB[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
