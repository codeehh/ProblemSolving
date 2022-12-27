#include <iostream>
using namespace std;

int h[50000];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += 2 * (h[i] * h[i] + h[i + 1] * h[i + 1]);
    }
    cout << ans;

    return 0;
}