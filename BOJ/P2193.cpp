#include <iostream>
using namespace std;

long long cache[91][2];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    cache[1][0] = 0;
    cache[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        cache[i][0] = cache[i - 1][0] + cache[i - 1][1];
        cache[i][1] = cache[i - 1][0];
    }

    cout << cache[n][0] + cache[n][1];

    return 0;
}