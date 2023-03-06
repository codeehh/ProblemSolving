#include <iostream>
using namespace std;

const int INF = 987654321;

int cache[101][100001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    int coins[101];
    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
    }
    for (int i = 1; i <= n; i++) {
        cache[i][coins[i]] = 1;
        for (int j = 1; j <= k; j++) {
            if (j < coins[i]) {
                cache[i][j] = cache[i - 1][j];
            } else if (j > coins[i]) {
                if (cache[i - 1][j] == 0 && cache[i][j - coins[i]] == 0) {
                    continue;
                }
                cache[i][j] = min(cache[i - 1][j] == 0 ? INF : cache[i - 1][j], cache[i][j - coins[i]] == 0 ? INF : cache[i][j - coins[i]] + 1);
            }
        }
    }
    cout << (cache[n][k] == 0 ? -1 : cache[n][k]);

    return 0;
}