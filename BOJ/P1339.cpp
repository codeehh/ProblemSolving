#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    long long cnt[26] = {0L};
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            long long a = 1L;
            for (int k = 0; k < str.length() - j - 1; k++) {
                a *= 10L;
            }
            cnt[str[j] - 'A'] += a;
        }
    }
    sort(cnt, cnt + 26, greater<>());
    long long ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += (cnt[i] * (9 - i));
    }
    cout << ans;

    return 0;
}