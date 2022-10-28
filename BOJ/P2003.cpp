#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int arr[10000];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int p1 = 0, p2 = 0;
    int sum = arr[p1];
    int cnt = 0;
    while (p1 < n && p2 < n) {
        if (sum == m) {
            cnt++;
            sum += arr[++p2];
            sum -= arr[p1++];
        } else if (sum < m) {
            sum += arr[++p2];
        } else if (sum > m) {
            sum -= arr[p1++];
        }
    }
    cout << cnt;
    return 0;
}