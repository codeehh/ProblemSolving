#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int arr[500000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int p1 = 0, p2 = 0;
    int sum = arr[0];
    int ans = 0;
    while (p1 < n && p2 < n) {
        if (sum <= m) {
            ans = max(ans, sum);
            sum += arr[++p2];
        } else {
            sum -= arr[p1++];
        }
    }
    cout << ans;
    return 0;
}