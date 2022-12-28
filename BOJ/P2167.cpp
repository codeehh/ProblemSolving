#include <iostream>
using namespace std;

int board[301][301];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
            board[i][j] += (board[i - 1][j] + board[i][j - 1] - board[i - 1][j - 1]);
        }
    }
    int k;
    cin >> k;
    while (k--) {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        cout << board[x][y] - board[x][j - 1] - board[i - 1][y] + board[i - 1][j - 1] << "\n";
    }

    return 0;
}