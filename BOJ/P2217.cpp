#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<>());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, arr[i] * (i + 1));
    }
    cout << ans;

    return 0;
}