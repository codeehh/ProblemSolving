#include <iostream>
#include <cstring>
using namespace std;

int cost[1000][3];
int dp[1000][3];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }
    int ans = 987654321;
    for (int s = 0; s < 3; s++) {
        memset(dp, 0, sizeof(dp));
        dp[0][s] = cost[0][s];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (j == k || dp[i - 1][k] == 0 || (i == n - 1 && j == s)) {
                        continue;
                    }
                    if (dp[i][j] == 0 || dp[i][j] > dp[i - 1][k] + cost[i][j]) {
                        dp[i][j] = dp[i - 1][k] + cost[i][j];
                    }
                }
            }
        }
        for (int j = 0; j < 3; j++) {
            if (dp[n - 1][j] != 0 && dp[n - 1][j] < ans) {
                ans = dp[n - 1][j];
            }
        }
    }
    cout << ans;

    return 0;
}