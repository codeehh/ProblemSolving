#include <iostream>
using namespace std;

const int INF = (1LL << 31) - 1;

int mat[500][2];
int dp[500][500];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> mat[i][0] >> mat[i][1];
    }
    for (int len = 2; len <= n; len++) {
        for (int b = 0; b + len - 1 < n; b++) {
            int e = b + len - 1;
            dp[b][e] = INF;
            for (int i = 0; i < len - 1; i++) {
                dp[b][e] = min(dp[b][e], dp[b][b + i] + dp[b + i + 1][e] + mat[b][0] * mat[b + i][1] * mat[e][1]);
            }
        }
    }
    cout << dp[0][n - 1];

    return 0;
}