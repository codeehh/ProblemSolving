#include <iostream>
using namespace std;

int coins[101];
int cache[100001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
    }
    for (int i = 1; i <= n; i++) {
        cache[coins[i]]++;
        for (int j = 1; j <= k; j++) {
            if (j - coins[i] >= 0)
                cache[j] += cache[j - coins[i]];
        }
    }
    cout << cache[k];
    return 0;
}