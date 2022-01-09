#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
string str;
vector<string> v;
int cnt_0;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        v.push_back(str);
    }
}
void divide(int n, int row, int col) {
    cnt_0 = 0;
    for (int i = row; i < row + n; i++) {
        for (int j = col; j < col + n; j++) {
            if (v[i][j] == '0') cnt_0++;
        }
    }
    if (cnt_0 == n*n) cout <<0;
    else if (cnt_0 == 0) cout << 1;
    else {
        cout << "(";
        divide(n/2, row, col);
        divide(n/2, row, col+n/2);
        divide(n/2, row+n/2, col);
        divide(n/2, row+n/2, col +n/2);
        cout << ")";
    }
}
int main() {
    input();
    divide(N, 0, 0);

    return 0;
}
