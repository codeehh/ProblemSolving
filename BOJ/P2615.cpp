#include <iostream>
using namespace std;

int board[20][20];

int check(int y, int x) {
    int color = board[y][x];
    if (y >= 5 && x <= 15) {
        int win = color;
        if (y != 19 && x != 1 && board[y + 1][x - 1] == color)
            win = 0;
        else if (y != 5 && x != 15 && board[y - 5][x + 5] == color)
            win = 0;
        else {
            for (int i = 1; i <= 4; i++) {
                if (board[y - i][x + i] != color) {
                    win = 0;
                    break;
                }
            }
        }
        if (win == color)
            return color;
    }
    if (x <= 15) {
        int win = color;
        if (x != 1 && board[y][x - 1] == color)
            win = 0;
        else if (x != 15 && board[y][x + 5] == color)
            win = 0;
        else {
            for (int i = 1; i <= 4; i++) {
                if (board[y][x + i] != color) {
                    win = 0;
                    break;
                }
            }
        }
        if (win == color)
            return color;
    }
    if (y <= 15 && x <= 15) {
        int win = color;
        if (y != 1 && x != 1 && board[y - 1][x - 1] == color)
            win = 0;
        else if (y != 15 && x != 15 && board[y + 5][x + 5] == color)
            win = 0;
        else {
            for (int i = 1; i <= 4; i++) {
                if (board[y + i][x + i] != color) {
                    win = 0;
                    break;
                }
            }
        }
        if (win == color)
            return color;
    }
    if (y <= 15) {
        int win = color;
        if (y != 1 && board[y - 1][x] == color)
            win = 0;
        else if (y != 15 && board[y + 5][x] == color)
            win = 0;
        else {
            for (int i = 1; i <= 4; i++) {
                if (board[y + i][x] != color) {
                    win = 0;
                    break;
                }
            }
        }
        if (win == color)
            return color;
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 19; i++)
        for (int j = 1; j <= 19; j++)
            cin >> board[i][j];

    for (int i = 1; i <= 19; i++) {
        for (int j = 1; j <= 19; j++) {
            int ans = check(i, j);
            if (ans) {
                cout << ans << '\n'
                     << i << ' ' << j;
                return 0;
            }
        }
    }
    cout << "0";
    return 0;
}