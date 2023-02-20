#include <iostream>
using namespace std;

int arr[1001];
int cache[1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        int maxIdx = 0;
        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[i]) {
                if (cache[j] > cache[maxIdx]) {
                    maxIdx = j;
                }
            }
        }
        cache[i] = cache[maxIdx] + arr[i];
        ans = max(ans, cache[i]);
    }
    cout << ans;

    return 0;
}