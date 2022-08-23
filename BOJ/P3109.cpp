#include <iostream>
using namespace std;

int r, c;
char board[10000][500];
bool finish = false;
int ans = 0;

void link(int y, int x) {
    //방문 표시
    board[y][x] = 'o';
    //마지막 열 도달하는 경우
    if (x == c - 1) {
        finish = true;
        ans++;
        return;
    }
    //재귀
    for (int i = 0; i < 3; i++) {
        if (finish)
            return;
        int ny = y + i - 1;
        int nx = x + 1;
        if (0 <= ny && ny < r && board[ny][nx] == '.') {
            link(ny, nx);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        finish = false;
        link(i, 0);
    }
    cout << ans;

    return 0;
}