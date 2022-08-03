#include <iostream>
using namespace std;

int cache[100][10];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int j = 1; j < 10; j++) {
        cache[0][j] = 1;
    }
    for (int i = 1; i < 100; i++) {
        cache[i][0] = cache[i - 1][1];
        for (int j = 1; j < 9; j++) {
            cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j + 1]) % 1000000000;
        }
        cache[i][9] = cache[i - 1][8];
    }

    int ans = 0;
    for (int j = 0; j < 10; j++) {
        ans += cache[n - 1][j];
        ans %= 1000000000;
    }
    cout << ans;
    return 0;
}