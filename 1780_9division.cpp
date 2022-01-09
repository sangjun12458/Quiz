#include <iostream>

using namespace std;

int N;
int arr[2200][2200];
int result[3];

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> arr[i][j];
    }
}
bool check(int n, int r, int c) {
    for (int i = r; i < r + n; i++) {
        for (int j = c; j < c + n; j++) {
            if (arr[r][c] != arr[i][j]) return false;
        }
    }
    return true;
}
void divide(int num, int row, int col) {
    if (num < 1) return;
    if (check(num, row, col)) {
        if (arr[row][col] == -1) result[0]++;
        else if (arr[row][col] == 0) result[1]++;
        else if (arr[row][col] == 1) result[2]++;
    }
    else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                divide(num/3, row+i*num/3, col+j*num/3);
            }
        }
    }
}
int main() {
    input();
    divide(N, 0, 0);
    for (int i = 0; i < 3; i++) cout << result[i] << '\n';

    return 0;
}
