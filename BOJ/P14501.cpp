#include <iostream>
using namespace std;

int n;
int arr[15][2];
int cache[16];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
        arr[i][0] += i;
    }
    for (int i = n - 1; i >= 0; i--) {
        cache[i] = cache[i + 1];
        if (arr[i][0] <= n)
            cache[i] = max(cache[i], cache[arr[i][0]] + arr[i][1]);
    }
    cout << cache[0];

    return 0;
}

// int n;
// int arr[16][2];
// int ans = 0;

// void solve(int idx, int money) {
//     if (idx > n) {
//         ans = max(ans, money);
//         return;
//     }
//     if (idx + arr[idx][0] <= n + 1)
//         solve(idx + arr[idx][0], money + arr[idx][1]);
//     solve(idx + 1, money);
// }

// int main(void) {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     cin >> n;
//     for (int i = 1; i <= n; i++) {
//         cin >> arr[i][0] >> arr[i][1];
//     }
//     solve(1, 0);
//     cout << ans;

//     return 0;
// }