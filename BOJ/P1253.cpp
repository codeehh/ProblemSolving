#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[2000];

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int p1 = 0;
        int p2 = n - 1;
        while (p1 < p2) {
            if (p1 == i) {
                p1++;
                continue;
            }
            if (p2 == i) {
                p2--;
                continue;
            }
            int sum = arr[p1] + arr[p2];
            if (arr[i] == sum) {
                ans++;
                break;
            }
            if (arr[i] < sum) {
                p2--;
            } else if (arr[i] > sum) {
                p1++;
            }
        }
    }

    cout << ans;
    return 0;
}