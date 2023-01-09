#include <iostream>
using namespace std;

int arr[200001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (b == arr[a]) {
            ans++;
        } else {
            arr[a] = 1 - arr[a];
            cnt += (b == 1 ? 1 : -1);
        }
    }
    ans += cnt;
    cout << ans;

    return 0;
}