#include <iostream>

using namespace std;

int N;
int map[129][129];
int cnt0 = 0;
int cnt_w = 0;
int cnt_b = 0;

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) cin >> map[i][j];
    }
}
void divide(int n, int row, int col) {
    cnt0 = 0;
    for (int i = row; i < row + n; i++) {
        for (int j = col; j < col + n; j++) {
            if (map[i][j] == 0) cnt0++;
        }
    }
    if (cnt0 != n*n && cnt0 != 0) {
        divide(n/2, row, col);
        divide(n/2, row, col+n/2);
        divide(n/2, row+n/2, col);
        divide(n/2, row+n/2, col+n/2);
    }
    else {
        if (cnt0 == n*n) cnt_w++;
        else cnt_b++;
    }
}
int main() {
    input();
    divide(N, 1, 1);
    cout << cnt_w << '\n' << cnt_b;

    return 0;
}
