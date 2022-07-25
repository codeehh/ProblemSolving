#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int cnt[10] = {0};
    while (n != 0) {
        cnt[n % 10]++;
        n /= 10;
    }

    long long ans = 0;
    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < cnt[i]; j++) {
            ans *= 10;
            ans += i;
        }
    }

    cout << ans;
    return 0;
}