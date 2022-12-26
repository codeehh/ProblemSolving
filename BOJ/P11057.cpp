#include <iostream>
using namespace std;

int cache[1002][10];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int j = 0; j < 10; j++) {
        cache[1][j] = 1;
    }

    for (int i = 2; i <= n + 1; i++) {
        cache[i][0] = cache[i - 1][0];
        for (int j = 1; j < 10; j++) {
            cache[i][j] = cache[i][j - 1] + cache[i - 1][j];
            cache[i][j] %= 10007;
        }
    }
    cout << cache[n + 1][9];

    return 0;
}