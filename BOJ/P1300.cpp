#include <iostream>
using namespace std;

int n, k;

int func(long long mid) {
    long long cnt = 0;
    long long sameCnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += min((long long)n, mid / i);
        if (mid <= (long long)n * i && mid % i == 0) {
            sameCnt++;
            cnt--;
        }
    }
    if (k <= cnt)
        return 1;
    else if (cnt < k && k <= cnt + sameCnt)
        return 0;
    else
        return -1;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    long long lo = 1;
    long long hi = (long long)n * n;
    long long mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        int result = func(mid);
        if (result == 0) {
            break;
        } else if (result == -1) {
            lo = mid + 1;
        } else if (result == 1) {
            hi = mid - 1;
        }
    }
    cout << mid;

    return 0;
}