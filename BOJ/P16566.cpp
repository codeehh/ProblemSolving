#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp[2];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        dp[0].push_back(a);
        dp[1].push_back(i);
    }
    sort(dp[0].begin(), dp[0].end());

    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        auto iter = upper_bound(dp[0].begin(), dp[0].end(), a);
        int idx = iter - dp[0].begin();
        int temp = idx;
        while (temp != dp[1][temp]) {
            temp = dp[1][temp];
        }
        cout << dp[0][temp] << "\n";
        dp[1][temp] = dp[1][temp + 1];
        dp[1][idx] = dp[1][temp];
    }

    return 0;
}