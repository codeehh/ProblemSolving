#include <iostream>
using namespace std;

int cache[100001][2];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    cache[1][0] = 1;
    cache[1][1] = 2;
    for (int i = 2; i <= n; i++) {
        cache[i][0] = (cache[i - 1][0] + cache[i - 1][1]) % 9901;
        cache[i][1] = (cache[i - 1][0] * 2 + cache[i - 1][1]) % 9901;
    }
    cout << (cache[n][0] + cache[n][1]) % 9901;

    return 0;
}