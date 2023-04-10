#include <iostream>
using namespace std;

const int INF = 987654321;

int arr[1000];
int cache[1001];

int binarySearch(int lo, int hi, int val) {
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (cache[mid] > val) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return hi;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cache[0] = INF;
    int n;
    cin >> n;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        int len = binarySearch(0, maxLen, arr[i]);
        cache[len + 1] = max(cache[len + 1], arr[i]);
        maxLen = max(maxLen, len + 1);
    }
    cout << maxLen;

    return 0;
}