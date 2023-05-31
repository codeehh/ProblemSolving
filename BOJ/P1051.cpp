#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    char board[50][50];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c = board[i][j];
            for (int k = 1; i + k < n && j + k < m; k++) {
                if (c == board[i + k][j] && c == board[i][j + k] && c == board[i + k][j + k]) {
                    ans = max(ans, (k + 1) * (k + 1));
                }
            }
        }
    }
    cout << ans;

    return 0;
}