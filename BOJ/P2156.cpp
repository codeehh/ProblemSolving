#include <iostream>
using namespace std;

int arr[10000];
int cache[10000];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n == 1) {
        cout << arr[0];
        return 0;
    }
    cache[0] = arr[0];
    cache[1] = arr[0] + arr[1];
    cache[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
    cache[3] = max(arr[0] + arr[1] + arr[3], arr[0] + arr[2] + arr[3]);
    for (int i = 4; i < n; i++) {
        cache[i] = max(max(cache[i - 2], cache[i - 3]) + arr[i], max(cache[i - 3], cache[i - 4]) + arr[i - 1] + arr[i]);
    }
    cout << max(cache[n - 1], cache[n - 2]);
    return 0;
}