#include <iostream>
using namespace std;

int n, s;
int arr[20];
int ans = 0;

void solve(int idx, int sum) {
    if (idx == n) {
        if (sum == s)
            ans++;
        return;
    }
    solve(idx + 1, sum);
    solve(idx + 1, sum + arr[idx]);
}

main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    solve(0, 0);
    if (s == 0)
        ans--;
    cout << ans;
    return 0;
}