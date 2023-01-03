#include <iostream>
#include <algorithm>
using namespace std;

int arr[15000];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int p1 = 0, p2 = n - 1;
    int ans = 0;
    while (p1 < p2) {
        int sum = arr[p1] + arr[p2];
        if (sum == m) {
            ans++;
            p1++;
            p2--;
        } else if (sum < m) {
            p1++;
        } else if (sum > m) {
            p2--;
        }
    }
    cout << ans;

    return 0;
}