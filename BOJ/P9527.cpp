#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b;
    cin >> a >> b;

    long long ans = 0;

    long long cnt = b - a + 1;

    long long pow = 2;
    while (b >= pow / 2) {
        long long remain = cnt % pow;
        long long start = a % pow;
        ans += (cnt - remain) / 2;
        ans += (start < pow / 2 ? min(max(remain - (pow / 2 - start), 0LL), pow / 2) : min(remain - max((start + remain - 1 >= pow + pow / 2 ? pow / 2 : start + remain - pow), 0LL), pow / 2));
        pow <<= 1;
    }

    cout << ans;
    return 0;
}