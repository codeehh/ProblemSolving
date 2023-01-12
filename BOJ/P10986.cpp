#include <iostream>
using namespace std;

int cnt[1000];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    long long ans = 0;
    int sum = 0;
    cnt[0]++;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        sum = (sum + a) % m;
        cnt[sum]++;
    }
    for (int i = 0; i < m; i++) {
        ans += ((long long)cnt[i] * (cnt[i] - 1)) / 2;
    }
    cout << ans;

    return 0;
}