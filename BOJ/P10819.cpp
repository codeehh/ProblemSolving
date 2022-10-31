#include <iostream>
#include <cmath>
using namespace std;

int n;
int arr[8];
int ans = 0;

void solve(int idx) {
    if (idx == n) {
        int sum = 0;
        for (int i = 1; i < n; i++) {
            sum += abs(arr[i - 1] - arr[i]);
        }
        ans = max(ans, sum);
        return;
    }
    for (int i = idx; i < n; i++) {
        swap(arr[idx], arr[i]);
        solve(idx + 1);
        swap(arr[idx], arr[i]);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    solve(0);
    cout << ans;
    return 0;
}