#include <iostream>
using namespace std;

int cache[1001][1001];

int solve(int n, int k) {
    if (k == 0 || n == k)
        return 1;
    int& a = cache[n - 1][k];
    int& b = cache[n - 1][k - 1];
    if (a == 0)
        a = solve(n - 1, k);
    if (b == 0)
        b = solve(n - 1, k - 1);
    return (a + b) % 10007;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    cout << solve(n, k);

    return 0;
}