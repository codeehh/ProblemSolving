#include <iostream>
#include <cstring>
using namespace std;

int board[10][10];
int temp[10][10];
int ans = -1;

void flip(int r, int c) {
    temp[r][c] = 1 - temp[r][c];
    if (r > 0)
        temp[r - 1][c] = 1 - temp[r - 1][c];
    if (r < 9)
        temp[r + 1][c] = 1 - temp[r + 1][c];
    if (c > 0)
        temp[r][c - 1] = 1 - temp[r][c - 1];
    if (c < 9)
        temp[r][c + 1] = 1 - temp[r][c + 1];
}

void solve(int bit) {
    int cnt = 0;
    for (int j = 0; j < 10; j++) {
        if ((bit & (1 << j)) != 0) {
            cnt++;
            flip(0, j);
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10; j++) {
            if (temp[i][j] == 1) {
                cnt++;
                flip(i + 1, j);
            }
        }
    }
    for (int j = 0; j < 10; j++) {
        if (temp[9][j] == 1)
            return;
    }
    if (ans == -1 || ans > cnt)
        ans = cnt;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char c;
            cin >> c;
            if (c == '#')
                board[i][j] = 0;
            else if (c == 'O')
                board[i][j] = 1;
        }
    }
    for (int i = 0; i < (1 << 10); i++) {
        memcpy(temp, board, sizeof(temp));
        solve(i);
    }
    cout << ans;

    return 0;
}