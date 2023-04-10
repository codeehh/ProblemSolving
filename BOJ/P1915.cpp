#include <iostream>
using namespace std;

char board[1001][1001];
int cache[1001][1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j] == '1') {
                cache[i][j] = min(cache[i - 1][j - 1], min(cache[i - 1][j], cache[i][j - 1])) + 1;
                ans = max(ans, cache[i][j] * cache[i][j]);
            }
        }
    }
    cout << ans;

    return 0;
}