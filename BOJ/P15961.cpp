#include <iostream>
using namespace std;

int arr[3000000];
int cnt[3001];

int sushiCnt = 0;
int maxSushiCnt = 0;
int coupon = 0;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, d, k, c;
    cin >> n >> d >> k >> c;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int p1 = 0;
    int p2 = k - 1;
    for (int i = p1; i <= p2; i++) {
        if ((++cnt[arr[i]]) == 1) {
            sushiCnt++;
        }
    }
    do {
        coupon = cnt[c] == 0 ? 1 : 0;
        maxSushiCnt = max(maxSushiCnt, sushiCnt + coupon);
        // cout << p1 << " ~ " << p2 << " : " << sushiCnt << " + " << coupon << '\n';
        p2 = (p2 + 1) % n;
        if ((--cnt[arr[p1]]) == 0) {
            sushiCnt--;
        }
        if ((++cnt[arr[p2]]) == 1) {
            sushiCnt++;
        }
        p1 = (p1 + 1) % n;
    } while (p1 != 0);
    cout << maxSushiCnt;
    return 0;
}