#include <iostream>
using namespace std;

int board[1001][1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
            board[i][j] += max(board[i - 1][j], board[i][j - 1]);
        }
    }
    cout << board[n][m];

    return 0;
}