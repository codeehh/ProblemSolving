#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[100000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int p1 = 0, p2 = n - 1;
    int minDist = 2000000000;
    int ans[2];
    while (p1 < p2) {
        int sum = arr[p1] + arr[p2];
        if (minDist > abs(sum)) {
            minDist = abs(sum);
            ans[0] = arr[p1];
            ans[1] = arr[p2];
        }
        if (sum == 0) {
            break;
        } else if (sum < 0) {
            p1++;
        } else {
            p2--;
        }
    }
    cout << ans[0] << " " << ans[1];
    return 0;
}